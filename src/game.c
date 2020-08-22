#include <nusys.h>
#include <math.h>
#include "common.h"
#include "game.h"
#include "graphics.h"
#include "camera.h"
#include "object.h"
#include "plane.h"
#include "collision.h"

#include "models/stage.h"
// #include "models/stage_opa.h"
#include "models/paddle.h"
#include "models/ball.h"
#include "models/brick.h"

#define ROT_VELOCITY 1.0f

#define UNIT_SIZE 200
#define STAGE_BLOCK_W 5
#define PADDLE_W 400
#define PADDLE_R (PADDLE_W / 2)
#define BALL_W 100.0
#define BALL_R (BALL_W / 2)
#define BRICK_W UNIT_SIZE
#define BRICK_R (UNIT_SIZE / 2)
#define BRICK_CR (BRICK_W * 1.2247449f)

#define NUM_BRICKS (STAGE_BLOCK_W * STAGE_BLOCK_W)
#define STAGE_W (UNIT_SIZE * STAGE_BLOCK_W)
#define STAGE_D (STAGE_W * 2)

#define PADDLE_MIN_X (-(STAGE_W / 2) - (PADDLE_W / 4))
#define PADDLE_MAX_X ((STAGE_W / 2) + (PADDLE_W / 4))
#define PADDLE_MIN_Y (-(STAGE_W / 2) - (PADDLE_W / 4))
#define PADDLE_MAX_Y ((STAGE_W / 2) + (PADDLE_W / 4))

#define BALL_MIN_X (-(STAGE_W / 2) + BALL_R)
#define BALL_MAX_X ((STAGE_W / 2) - BALL_R)
#define BALL_MIN_Y (-(STAGE_W / 2) + BALL_R)
#define BALL_MAX_Y ((STAGE_W / 2) - BALL_R)
#define BALL_MIN_Z (-(UNIT_SIZE * 2) - BALL_R)
#define BALL_MAX_Z ((STAGE_W) - BALL_R)

#define MOVE_VELOCITY (350.0 * STAGE_BLOCK_W)
#define BALL_VELOCITY (200.0 * STAGE_BLOCK_W)
#define BALL_START_VELOCITY 1

#define CAMERA_MOVE_SCALE 0.25

#define BRICK_DEATH_ANIM_DURATION 0.1
#define BRICK_HIT_ANIM_DURATION 0.1
#define PADDLE_HIT_ANIM_DURATION 0.2
#define PADDLE_HIT_ANIM_INTENSITY 20.0f

extern NUContData controller[1];

static Object stage;
static Object ball;

static bool paused = TRUE;
static bool live = TRUE;

enum {
  SIDE_LEFT = 0,
  SIDE_RIGHT = 1,
  SIDE_TOP = 2,
  SIDE_BOTTOM = 3,
  SIDE_FRONT = 4,
  SIDE_BACK = 5
};

typedef struct {
  Object obj;
  double hit_anim_timer;
  Vec3f hit_rot;
  bool held;
  Vec3f hold_pos;
} Paddle;

static Paddle paddle;

typedef struct {
  float left;
  float right;
  float top;
  float bottom;
  float front;
  float back;
  u8 lives;
  Object obj;
  double death_anim_timer;
  double hit_anim_timer;
} Brick;

static Brick bricks[NUM_BRICKS];

static Plane walls[6];

// Check each wall for collision with the ball.
// If there is a collision, move the ball to the collision point and return a new next_pos.
// In this event, collision needs to be checked again with the new next_pos, in case another
// collision occurs.
static bool handle_collision_walls(Vec3f next_pos, float dist, Vec3f* new_next_pos) {
  bool intersection = FALSE;
  Vec3f hit;
  float time, dist_after_hit;

  // Check up to 3 walls, depending on the direction the ball is travelling.
  // For instance, if the ball is travelling in the -X direction, there is no need to check
  // the right wall, as it's only possible for the ball to hit the left wall when travelling left.
  // Additionally, collision checking is skipped if the next position is still within level bounds.

  // Check left wall
  if (ball.vel.x < 0 &&
      next_pos.x <= BALL_MIN_X &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, walls[SIDE_LEFT], &hit, &time)) {
    // Flip x direction
    ball.vel.x *= -1;
    intersection = TRUE;
  }
  // Check right wall
  if (ball.vel.x > 0 &&
      next_pos.x >= BALL_MAX_X &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, walls[SIDE_RIGHT], &hit, &time)) {
    // Flip x direction
    ball.vel.x *= -1;
    intersection = TRUE;
  }
  // Check top wall
  if (ball.vel.y > 0 &&
      next_pos.y >= BALL_MAX_Y &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, walls[SIDE_TOP], &hit, &time)) {
    // Flip y direction
    ball.vel.y *= -1;
    intersection = TRUE;
  }
  // Check bottom wall
  if (ball.vel.y < 0 &&
      next_pos.y <= BALL_MIN_Y &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, walls[SIDE_BOTTOM], &hit, &time)) {
    // Flip y direction
    ball.vel.y *= -1;
    intersection = TRUE;
  }
  // Check back wall
  if (ball.vel.z < 0 &&
      next_pos.z <= BALL_MIN_Z &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, walls[SIDE_BACK], &hit, &time)) {
    // Flip z direction
    ball.vel.z *= -1;
    intersection = TRUE;
  }
  // Check front wall
  if (ball.vel.z > 0 &&
      next_pos.z >= BALL_MAX_Z &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, walls[SIDE_FRONT], &hit, &time)) {
    // Check if the intersection point lies within the bounds of the paddle
    if (hit.x >= paddle.obj.pos.x - PADDLE_R - BALL_R && hit.x <= paddle.obj.pos.x + PADDLE_R + BALL_R &&
        hit.y >= paddle.obj.pos.y - PADDLE_R - BALL_R && hit.y <= paddle.obj.pos.y + PADDLE_R + BALL_R) {
      // If so, set the ball's direction to a brand new angle based on its position relative to the paddle's centre
      vec3f_set(
        ball.vel,
        -(hit.x - paddle.obj.pos.x) / PADDLE_R,
        -(hit.y - paddle.obj.pos.y) / PADDLE_R,
        -ball.vel.z
      );
      intersection = TRUE;
      // Calculate the hit animation rotation for this hit
      vec3f_set(
        paddle.hit_rot,
        (-(hit.y - paddle.obj.pos.y) / PADDLE_R) * PADDLE_HIT_ANIM_INTENSITY,
        ((hit.x - paddle.obj.pos.x) / PADDLE_R) * PADDLE_HIT_ANIM_INTENSITY,
        0
      );
      // If the A button is held on this frame, hold the ball
      if (controller[0].button & A_BUTTON) {
        paddle.held = TRUE;
        vec3f_set(
          paddle.hold_pos,
          hit.x - paddle.obj.pos.x,
          hit.y - paddle.obj.pos.y,
          hit.z - paddle.obj.pos.z
        );
        *new_next_pos = hit;
        return FALSE;
      }
      // Otherwise, start the hit animation
      else {
        paddle.hit_anim_timer = PADDLE_HIT_ANIM_DURATION;
      }
    }
    // If the ball doesn't hit the paddle but still intersects with the front wall, it's an out
    // For now, just respawn the ball
    else {
      live = FALSE;
      return FALSE;
    }
  }

  if (intersection) {
    // Move the ball to the intersection point
    ball.pos = hit;

    // Calculate the portion of the ball's movement that occurs after collision
    dist_after_hit = (1.0f - time) * dist;

    // Return the new next position so further testing can be done
    // between the point of intersection and the new next position
    vec3f_set(
      *new_next_pos,
      ball.pos.x + ball.vel.x * dist_after_hit,
      ball.pos.y + ball.vel.y * dist_after_hit,
      ball.pos.z + ball.vel.z * dist_after_hit
    );

    return TRUE;
  }

  // In the event that there is no collision at all, just return the original next_pos
  return FALSE;
}

// Check each brick for collision with the ball.
// If there is a collision, move the ball to the collision point and return a new next_pos.
// In this event, collision needs to be checked again with the new next_pos, in case another
// collision occurs.
static bool handle_collision_bricks(Vec3f next_pos, float dist, Vec3f* new_next_pos) {
  bool intersection = FALSE;
  Vec3f hit;
  float time, dist_after_hit;
  int i;

  for (i = 0; i < NUM_BRICKS; i++) {
    // Check the distance from the ball to the cube and see if it's worth doing collision detection
    float dist_to_brick = sqrtf(
      pow(bricks[i].obj.pos.x - ball.pos.x, 2) +
      pow(bricks[i].obj.pos.y - ball.pos.y, 2) +
      pow(bricks[i].obj.pos.z - ball.pos.z, 2)
    ) - BALL_R - BRICK_CR;

    if (dist_to_brick - dist >= 0) {
      continue;
    }

    {
      Vec3f left[] = {
        {bricks[i].left, bricks[i].top, bricks[i].back},
        {bricks[i].left, bricks[i].top, bricks[i].front},
        {bricks[i].left, bricks[i].bottom, bricks[i].back},
        {bricks[i].left, bricks[i].bottom, bricks[i].front}
      };
      Vec3f right[] = {
        {bricks[i].right, bricks[i].top, bricks[i].front},
        {bricks[i].right, bricks[i].top, bricks[i].back},
        {bricks[i].right, bricks[i].bottom, bricks[i].front},
        {bricks[i].right, bricks[i].bottom, bricks[i].back}
      };
      Vec3f top[] = {
        {bricks[i].left, bricks[i].top, bricks[i].back},
        {bricks[i].right, bricks[i].top, bricks[i].back},
        {bricks[i].left, bricks[i].top, bricks[i].front},
        {bricks[i].right, bricks[i].top, bricks[i].front}
      };
      Vec3f bottom[] = {
        {bricks[i].left, bricks[i].bottom, bricks[i].front},
        {bricks[i].right, bricks[i].bottom, bricks[i].front},
        {bricks[i].left, bricks[i].bottom, bricks[i].back},
        {bricks[i].right, bricks[i].bottom, bricks[i].back}
      };
      Vec3f front[] = {
        {bricks[i].left, bricks[i].top, bricks[i].front},
        {bricks[i].right, bricks[i].top, bricks[i].front},
        {bricks[i].left, bricks[i].bottom, bricks[i].front},
        {bricks[i].right, bricks[i].bottom, bricks[i].front}
      };
      Vec3f back[] = {
        {bricks[i].right, bricks[i].top, bricks[i].back},
        {bricks[i].left, bricks[i].top, bricks[i].back},
        {bricks[i].right, bricks[i].bottom, bricks[i].back},
        {bricks[i].left, bricks[i].bottom, bricks[i].back}
      };

      // Don't check dead bricks
      if (bricks[i].lives == 0) {
        continue;
      }

      // Check three sides of the brick, depending on the ball's velocity
      // Check front face if travelling away from the camera
      if (ball.vel.z < 0 &&
          moving_sphere_quad_intersect(BALL_R, ball.pos, next_pos, front[0], front[1], front[2], front[3], &hit, &time)) {
        if (--bricks[i].lives > 0) {
          ball.vel.z *= -1;
          intersection = TRUE;
        } else {
          // Don't report a hit if the brick dies
          return FALSE;
        }
      }

      // Check left face if travelling right
      if (ball.vel.x > 0 &&
          !intersection &&
          moving_sphere_quad_intersect(BALL_R, ball.pos, next_pos, left[0], left[1], left[2], left[3], &hit, &time)) {
        if (--bricks[i].lives > 0) {
          ball.vel.x *= -1;
          intersection = TRUE;
        } else {
          return FALSE;
        }
      }

      // Check right face if travelling left
      if (ball.vel.x < 0 &&
          !intersection &&
          moving_sphere_quad_intersect(BALL_R, ball.pos, next_pos, right[0], right[1], right[2], right[3], &hit, &time)) {
        if (--bricks[i].lives > 0) {
          ball.vel.x *= -1;
          intersection = TRUE;
        } else {
          return FALSE;
        }
      }

      // Check top face if travelling down
      if (ball.vel.y < 0 &&
          !intersection &&
          moving_sphere_quad_intersect(BALL_R, ball.pos, next_pos, top[0], top[1], top[2], top[3], &hit, &time)) {
        if (--bricks[i].lives > 0) {
          ball.vel.y *= -1;
          intersection = TRUE;
        } else {
          return FALSE;
        }
      }

      // Check bottom face if travelling up
      if (ball.vel.y > 0 &&
          !intersection &&
          moving_sphere_quad_intersect(BALL_R, ball.pos, next_pos, bottom[0], bottom[1], bottom[2], bottom[3], &hit, &time)) {
        if (--bricks[i].lives > 0) {
          ball.vel.y *= -1;
          intersection = TRUE;
        } else {
          return FALSE;
        }
      }

      // Check back face if travelling towards from the camera
      if (ball.vel.z > 0 &&
          !intersection &&
          moving_sphere_quad_intersect(BALL_R, ball.pos, next_pos, back[0], back[1], back[2], back[3], &hit, &time)) {
        if (--bricks[i].lives > 0) {
          ball.vel.z *= -1;
          intersection = TRUE;
        } else {
          return FALSE;
        }
      }

      // If there was an intersection with any face of this brick,
      // start the hit animation timer
      if (intersection) {
        bricks[i].hit_anim_timer = BRICK_HIT_ANIM_DURATION;
        break;
      }
    }
  }

  if (intersection) {
    // Move the ball to the intersection point
    vec3f_copy(ball.pos, hit);

    // Calculate the portion of the ball's movement that occurs after collision
    dist_after_hit = (1.0f - time) * dist;

    // Return the new next position so further testing can be done
    // between the point of intersection and the new next position
    vec3f_set(
      *new_next_pos,
      ball.pos.x + ball.vel.x * dist_after_hit,
      ball.pos.y + ball.vel.y * dist_after_hit,
      ball.pos.z + ball.vel.z * dist_after_hit
    );

    return TRUE;
  }

  // In the event that there is no collision at all, just return the original next_pos
  return FALSE;
}

// Debug free camera
static void update_camera_free(double dt) {
  Vec2f rot;
  Vec3f velocity;
  vec2f_set(rot, 0, 0);
  vec3f_set(velocity, 0, 0, 0);

  // Rotate the camera if the C buttons are pressed
  if (controller[0].button & L_CBUTTONS) {
    rot.x = -1;
  }
  if (controller[0].button & R_CBUTTONS) {
    rot.x = 1;
  }
  if (controller[0].button & U_CBUTTONS) {
    rot.y = 1;
  }
  if (controller[0].button & D_CBUTTONS) {
    rot.y = -1;
  }

  if (fabs(rot.x) > EPSILON || fabs(rot.y) > EPSILON) {
    vec2f_mag(rot, ROT_VELOCITY);
    camera_rotate(rot);
  }

  // Move the camera if the joystick is moved
  if (controller[0].stick_y > DEADZONE || controller[0].stick_y < -DEADZONE) {
    velocity.z = controller[0].stick_y;
  }
  if (controller[0].stick_x > DEADZONE || controller[0].stick_x < -DEADZONE) {
    velocity.x = controller[0].stick_x;
  }
  if (controller[0].button & Z_TRIG || controller[0].button & L_TRIG) {
    velocity.y = 80;
  }
  if (controller[0].button & R_TRIG) {
    velocity.y = -80;
  }

  if (fabs(velocity.x) > EPSILON || fabs(velocity.y) > EPSILON || fabs(velocity.z) > EPSILON) {
    vec3f_norm(velocity);
    vec3f_mag(velocity, MOVE_VELOCITY);
    camera_move(velocity);
  }
}

static void update_camera(double dt) {
  Vec2f rot = {
    -(paddle.obj.pos.x / PADDLE_MAX_X) * 5,
    -(paddle.obj.pos.y / PADDLE_MAX_Y) * 5
  };
  camera_rotate_to(rot);
  camera.pos.x = paddle.obj.pos.x * CAMERA_MOVE_SCALE;
  camera.pos.y = paddle.obj.pos.y * CAMERA_MOVE_SCALE;
}

static void update_ball(double dt) {
  int i, j;
  bool hit;
  bool brick_hit;
  Vec3f move;
  Vec3f next_pos, new_next_pos;
  double dist = BALL_VELOCITY * dt;

  // Project the next ball position
  move.x = ball.vel.x * dist;
  move.y = ball.vel.y * dist;
  move.z = ball.vel.z * dist;
  next_pos.x = ball.pos.x + move.x;
  next_pos.y = ball.pos.y + move.y;
  next_pos.z = ball.pos.z + move.z;

  // Start collision detection
  do {
    // Check for a collision with the bricks first
    hit = handle_collision_bricks(next_pos, dist, &new_next_pos);

    // If there's no collision with the bricks, check for collision with the walls
    if (!hit) {
      hit = handle_collision_walls(next_pos, dist, &new_next_pos);
    }

    // If there is ultimately a collision in this iteration, move the ball to its corrected position
    if (hit) {
      next_pos = new_next_pos;
    }
  } while (hit); // Iterate until there are no more collisions to resolve this update

  // If the ball is still live, move it to its corrected new position
  if (live) {
    // Skip this if the ball is being held by the paddle
    if (!paddle.held) {
      ball.pos = next_pos;
    }
  }
  // Otherwise, respawn the ball
  else {
    vec3f_set(ball.pos, 0, 0, UNIT_SIZE);
    vec3f_set(ball.vel, 0, 0, BALL_START_VELOCITY);
    live = TRUE;
  }
}

static void update_paddle(double dt) {
  Vec3f velocity;
  vec3f_set(velocity, 0, 0, 0);

  if (controller[0].stick_y > DEADZONE || controller[0].stick_y < -DEADZONE) {
    velocity.y = controller[0].stick_y;
  }
  if (controller[0].stick_x > DEADZONE || controller[0].stick_x < -DEADZONE) {
    velocity.x = controller[0].stick_x;
  }

  if (fabs(velocity.x) > EPSILON || fabs(velocity.y) > EPSILON || fabs(velocity.z) > EPSILON) {
    vec3f_norm(velocity);
    vec3f_mag(velocity, MOVE_VELOCITY * dt);
    vec3f_add(paddle.obj.pos, velocity);

    // Clamp paddle position
    if (paddle.obj.pos.x < PADDLE_MIN_X) {
      paddle.obj.pos.x = PADDLE_MIN_X;
    }
    if (paddle.obj.pos.x > PADDLE_MAX_X) {
      paddle.obj.pos.x = PADDLE_MAX_X;
    }
    if (paddle.obj.pos.y < PADDLE_MIN_Y) {
      paddle.obj.pos.y = PADDLE_MIN_Y;
    }
    if (paddle.obj.pos.y > PADDLE_MAX_Y) {
      paddle.obj.pos.y = PADDLE_MAX_Y;
    }
  }

  // Tick down hit animation timer if it's running
  if (paddle.hit_anim_timer > 0) {
    float x;
    paddle.hit_anim_timer -= dt;

    if (paddle.hit_anim_timer < 0) {
      paddle.hit_anim_timer = 0;
    }

    x = (PADDLE_HIT_ANIM_DURATION - paddle.hit_anim_timer) / PADDLE_HIT_ANIM_DURATION;

    // Send paddle back a bit
    vec3f_set(
      paddle.obj.pos,
      paddle.obj.pos.x,
      paddle.obj.pos.y,
      sin(M_PI * x) * -(PADDLE_HIT_ANIM_INTENSITY * 5) + (STAGE_BLOCK_W * UNIT_SIZE)
    );

    // Rotate the paddle depending on hit position
    vec3f_set(
      paddle.obj.rot,
      sin(M_PI * x) * paddle.hit_rot.x,
      sin(M_PI * x) * paddle.hit_rot.y,
      0
    );
  }
}

static void update_bricks(double dt) {
  int i;

  for (i = 0; i < NUM_BRICKS; i++) {
    // Tick down death animation timer if it's running
    if (bricks[i].lives == 0 && bricks[i].death_anim_timer > 0) {
      bricks[i].death_anim_timer -= dt;

      if (bricks[i].death_anim_timer < 0) {
        bricks[i].death_anim_timer = 0;
      }

      bricks[i].obj.scale = (bricks[i].death_anim_timer / BRICK_DEATH_ANIM_DURATION);
    }

    // Tick down hit animation timer if it's running
    if (bricks[i].hit_anim_timer > 0) {
      bricks[i].hit_anim_timer -= dt;

      if (bricks[i].hit_anim_timer < 0) {
        bricks[i].hit_anim_timer = 0;
      }

      vec3f_set(
        bricks[i].obj.rot,
        sin(2 * M_PI * ((BRICK_HIT_ANIM_DURATION - bricks[i].hit_anim_timer) / BRICK_HIT_ANIM_DURATION)) * 10.0,
        0,
        sin(4 * M_PI * ((BRICK_HIT_ANIM_DURATION - bricks[i].hit_anim_timer) / BRICK_HIT_ANIM_DURATION)) * 6.0
      );
    }
  }
}

// Precalculate wall planes for easier collision detection
static void init_walls() {
  Vec3f left[] = {
    {BALL_MIN_X, BALL_MAX_Y, BALL_MAX_Z},
    {BALL_MIN_X, BALL_MAX_Y, BALL_MIN_Z},
    {BALL_MIN_X, BALL_MIN_Y, BALL_MAX_Z}
  };
  Vec3f right[] = {
    {BALL_MAX_X, BALL_MAX_Y, BALL_MIN_Z},
    {BALL_MAX_X, BALL_MAX_Y, BALL_MAX_Z},
    {BALL_MAX_X, BALL_MIN_Y, BALL_MIN_Z}
  };
  Vec3f top[] = {
    {BALL_MIN_X, BALL_MAX_Y, BALL_MAX_Z},
    {BALL_MAX_X, BALL_MAX_Y, BALL_MAX_Z},
    {BALL_MIN_X, BALL_MAX_Y, BALL_MIN_Z}
  };
  Vec3f bottom[] = {
    {BALL_MIN_X, BALL_MIN_Y, BALL_MIN_Z},
    {BALL_MAX_X, BALL_MIN_Y, BALL_MIN_Z},
    {BALL_MIN_X, BALL_MIN_Y, BALL_MAX_Z}
  };
  Vec3f front[] = {
    {BALL_MAX_X, BALL_MAX_Y, BALL_MAX_Z},
    {BALL_MIN_X, BALL_MAX_Y, BALL_MAX_Z},
    {BALL_MAX_X, BALL_MIN_Y, BALL_MAX_Z}
  };
  Vec3f back[] = {
    {BALL_MIN_X, BALL_MAX_Y, BALL_MIN_Z},
    {BALL_MAX_X, BALL_MAX_Y, BALL_MIN_Z},
    {BALL_MIN_X, BALL_MIN_Y, BALL_MIN_Z}
  };
  walls[SIDE_LEFT] = plane_from_points(left[0], left[1], left[2]);
  walls[SIDE_RIGHT] = plane_from_points(right[0], right[1], right[2]);
  walls[SIDE_TOP] = plane_from_points(top[0], top[1], top[2]);
  walls[SIDE_BOTTOM] = plane_from_points(bottom[0], bottom[1], bottom[2]);
  walls[SIDE_FRONT] = plane_from_points(front[0], front[1], front[2]);
  walls[SIDE_BACK] = plane_from_points(back[0], back[1], back[2]);
}

void game_init(void) {
  int i;

  camera_init();

  // Initialize stage
  vec3f_set(stage.pos, 0, 0, 0);
  vec3f_set(stage.rot, 0, 0, 0);
  vec3f_set(stage.vel, 0, 0, 0);
  stage.scale = STAGE_BLOCK_W;

  // Initialize paddle
  vec3f_set(paddle.obj.pos, 0, 0, STAGE_BLOCK_W * UNIT_SIZE);
  vec3f_set(paddle.obj.rot, 0, 0, 0);
  vec3f_set(paddle.obj.vel, 0, 0, 0);
  paddle.obj.scale = 2;
  paddle.hit_anim_timer = 0;
  paddle.held = FALSE;

  // Initialize ball
  vec3f_set(ball.pos, 0, 0, 450);
  vec3f_set(ball.rot, 0, 0, 0);
  vec3f_set(ball.vel, 0, 0, BALL_START_VELOCITY);
  ball.scale = 1;

  // Initialize bricks
  for (i = 0; i < NUM_BRICKS; i++) {
    float x = -(STAGE_BLOCK_W * BRICK_R - BRICK_R) + ((i % STAGE_BLOCK_W) * BRICK_W);
    float y = -(STAGE_BLOCK_W * BRICK_R - BRICK_R) + ((i / STAGE_BLOCK_W) * BRICK_W);

    vec3f_set(bricks[i].obj.pos, x, y, 0);
    vec3f_set(bricks[i].obj.rot, 0, 0, 0);
    bricks[i].obj.scale = 1;

    // Precalculate faces for easier collision detection
    bricks[i].left = x - BRICK_R;
    bricks[i].right = x + BRICK_R;
    bricks[i].top = y + BRICK_R;
    bricks[i].bottom = y - BRICK_R;
    bricks[i].back = -BRICK_R;
    bricks[i].front = BRICK_R;

    bricks[i].lives = 3;
    bricks[i].death_anim_timer = BRICK_DEATH_ANIM_DURATION;
  }

  // Precalculate wall planes
  init_walls();
}

void game_update(double dt) {
  // Check for a pause button press
  if (controller[0].trigger & START_BUTTON) {
    paused = !paused;
  }

  if (paused) {
    return;
  }

  update_paddle(dt);

  // Check if the ball is held
  if (paddle.held) {
    // Position the ball relative to the paddle
    ball.pos = paddle.hold_pos;
    vec3f_add(ball.pos, paddle.obj.pos);
    // Check for A button release
    if (!(controller[0].button & A_BUTTON)) {
      paddle.held = FALSE;
      paddle.hit_anim_timer = PADDLE_HIT_ANIM_DURATION;
    }
  } else {
    update_ball(dt);
  }

  update_camera(dt);
  update_bricks(dt);
}

void game_draw(void) {
  int i;
  MVP* mvpp = &mvp[task_num];
  glistp = &glist[task_num][0];

  graphics_init_RCP();
  graphics_clear(0, 0, 0);

  camera_look(mvpp);

  // Draw opaque objects first
  // Begin with the bricks
  for (i = 0; i < NUM_BRICKS; i++) {
    switch (bricks[i].lives) {
      case 3:
        graphics_draw_textured_object(&(bricks[i].obj), brick_Cube_mesh_green, FALSE);
        break;
      case 2:
        graphics_draw_textured_object(&(bricks[i].obj), brick_Cube_mesh_orange, FALSE);
        break;
      case 1:
        graphics_draw_textured_object(&(bricks[i].obj), brick_Cube_mesh_pink, FALSE);
        break;
      case 0:
        if (bricks[i].death_anim_timer > 0) {
          graphics_draw_textured_object(&(bricks[i].obj), brick_Cube_mesh_pink, FALSE);
        }
        break;
      default:
        break;
    }
  }

  // Draw the stage
  // graphics_draw_object(&stage, stage_opa_Cube_mesh, FALSE);
  graphics_draw_object(&stage, stage_Cube_mesh, FALSE);

  // Draw the ball
  graphics_draw_object(&ball, ball_Icosphere_mesh, FALSE);

  // Transparent objects drawn last
  graphics_draw_object(&paddle.obj, paddle_Cube_mesh, TRUE);

  gDPFullSync(glistp++);
  gSPEndDisplayList(glistp++);

  nuGfxTaskStart(
    &glist[task_num][0],
    (s32)(glistp - glist[task_num]) * sizeof(Gfx),
    NU_GFX_UCODE_F3DEX,
    NU_SC_SWAPBUFFER
  );

  task_num++;
  task_num %= MAX_TASKS;
}
