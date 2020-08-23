#include "paddle.h"

extern NUContData controller[1];

void paddle_init(Paddle* paddle, Level* level) {
  vec3f_set(paddle->obj.pos, 0, 0, level->width * UNIT_SIZE);
  vec3f_set(paddle->obj.rot, 0, 0, 0);
  vec3f_set(paddle->obj.vel, 0, 0, 0);
  paddle->obj.scale = 2;
  paddle->hit_anim_timer = 0;
  paddle->held = FALSE;
  paddle->min_x = -(level->width * BRICK_W / 2) - (PADDLE_W / 4);
  paddle->max_x = (level->width * BRICK_W / 2) + (PADDLE_W / 4);
  paddle->min_y = -(level->width * BRICK_W / 2) - (PADDLE_W / 4);
  paddle->max_y = (level->width * BRICK_W / 2) + (PADDLE_W / 4);
}

void paddle_update(Paddle* paddle, Level* level, double dt) {
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
    vec3f_mag(velocity, PADDLE_BASE_VELOCITY * dt);
    vec3f_add(paddle->obj.pos, velocity);

    // Clamp paddle position
    if (paddle->obj.pos.x < paddle->min_x) {
      paddle->obj.pos.x = paddle->min_x;
    }
    if (paddle->obj.pos.x > paddle->max_x) {
      paddle->obj.pos.x = paddle->max_x;
    }
    if (paddle->obj.pos.y < paddle->min_y) {
      paddle->obj.pos.y = paddle->min_y;
    }
    if (paddle->obj.pos.y > paddle->max_y) {
      paddle->obj.pos.y = paddle->max_y;
    }
  }

  // Tick down hit animation timer if it's running
  if (paddle->hit_anim_timer > 0) {
    float x;
    paddle->hit_anim_timer -= dt;

    if (paddle->hit_anim_timer < 0) {
      paddle->hit_anim_timer = 0;
    }

    x = (PADDLE_HIT_ANIM_DURATION - paddle->hit_anim_timer) / PADDLE_HIT_ANIM_DURATION;

    // Send paddle back a bit
    vec3f_set(
      paddle->obj.pos,
      paddle->obj.pos.x,
      paddle->obj.pos.y,
      sin(M_PI * x) * -(PADDLE_HIT_ANIM_INTENSITY * 5) + (level->bounds[SIDE_FRONT])
    );

    // Rotate the paddle depending on hit position
    vec3f_set(
      paddle->obj.rot,
      sin(M_PI * x) * paddle->hit_rot.x,
      sin(M_PI * x) * paddle->hit_rot.y,
      0
    );
  }
}
