#include "level.h"
#include "common.h"
#include "brick.h"
#include <malloc.h>

// Load a level from the given params
Level level_load(LevelData* data) {
  Level level;
  int x, y, z;

  level.start_vel = data->start_vel;
  level.width = data->width;
  level.height = data->height;
  level.depth = data->depth;
  level.num_bricks = level.width * level.height * level.depth;
  level.bricks = (Brick*)malloc(sizeof(Brick) * data->width * data->height * data->depth);

  // Initialize bricks
  for (z = 0; z < level.depth; z++) {
    for (y = 0; y < level.height; y++) {
      for (x = 0; x < level.width; x++) {
        int i = flatten3D(x, y, z, level.width, level.height);
        float left, right, top, bottom, back, front;

        vec3f_set(
          level.bricks[i].obj.pos,
          -(level.width * BRICK_R - BRICK_R) + x * BRICK_W,
          -(level.height * BRICK_R - BRICK_R) + y * BRICK_W,
          -(z * BRICK_W)
        );

        vec3f_set(level.bricks[i].obj.rot, 0, 0, 0);
        level.bricks[i].obj.scale = 1;

        // Precalculate face quads for easier collision detection
        left = level.bricks[i].obj.pos.x - BRICK_R;
        right = level.bricks[i].obj.pos.x + BRICK_R;
        top = level.bricks[i].obj.pos.y + BRICK_R;
        bottom = level.bricks[i].obj.pos.y - BRICK_R;
        back = level.bricks[i].obj.pos.z - BRICK_R;
        front = level.bricks[i].obj.pos.z + BRICK_R;

        // Left face
        vec3f_set(level.bricks[i].left[0], left, top, back);
        vec3f_set(level.bricks[i].left[1], left, top, front);
        vec3f_set(level.bricks[i].left[2], left, bottom, back);
        vec3f_set(level.bricks[i].left[3], left, bottom, front);

        // Right face
        vec3f_set(level.bricks[i].right[0], right, top, front);
        vec3f_set(level.bricks[i].right[1], right, top, back);
        vec3f_set(level.bricks[i].right[2], right, bottom, front);
        vec3f_set(level.bricks[i].right[3], right, bottom, back);

        // Top face
        vec3f_set(level.bricks[i].top[0], left, top, back);
        vec3f_set(level.bricks[i].top[1], right, top, back);
        vec3f_set(level.bricks[i].top[2], left, top, front);
        vec3f_set(level.bricks[i].top[3], right, top, front);

        // Bottom face
        vec3f_set(level.bricks[i].bottom[0], left, bottom, front);
        vec3f_set(level.bricks[i].bottom[1], right, bottom, front);
        vec3f_set(level.bricks[i].bottom[2], left, bottom, back);
        vec3f_set(level.bricks[i].bottom[3], right, bottom, back);

        // Back face
        vec3f_set(level.bricks[i].back[0], right, top, back);
        vec3f_set(level.bricks[i].back[1], left, top, back);
        vec3f_set(level.bricks[i].back[2], right, bottom, back);
        vec3f_set(level.bricks[i].back[3], left, bottom, back);

        // Front face
        vec3f_set(level.bricks[i].front[0], left, top, front);
        vec3f_set(level.bricks[i].front[1], right, top, front);
        vec3f_set(level.bricks[i].front[2], left, bottom, front);
        vec3f_set(level.bricks[i].front[3], right, bottom, front);

        level.bricks[i].lives = data->bricks[i];

        if (level.bricks[i].lives > 0) {
          level.bricks[i].death_anim_timer = BRICK_DEATH_ANIM_DURATION;
        }
      }
    }
  }

  // Precalculate level bounds
  level.bounds[SIDE_LEFT] = -level.width * BRICK_W / 2;
  level.bounds[SIDE_RIGHT] = level.width * BRICK_W / 2;
  level.bounds[SIDE_TOP] = level.height * BRICK_W / 2;
  level.bounds[SIDE_BOTTOM] = -level.height * BRICK_W / 2;
  level.bounds[SIDE_BACK] = -level.width * BRICK_W / 2;
  level.bounds[SIDE_FRONT] = level.width * BRICK_W;

  // Precalculate wall planes
  {
    Vec3f left[] = {
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_TOP], level.bounds[SIDE_FRONT]},
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_TOP], level.bounds[SIDE_BACK]},
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_BOTTOM], level.bounds[SIDE_FRONT]}
    };
    Vec3f right[] = {
      {level.bounds[SIDE_RIGHT], level.bounds[SIDE_TOP], level.bounds[SIDE_BACK]},
      {level.bounds[SIDE_RIGHT], level.bounds[SIDE_TOP], level.bounds[SIDE_FRONT]},
      {level.bounds[SIDE_RIGHT], level.bounds[SIDE_BOTTOM], level.bounds[SIDE_BACK]}
    };
    Vec3f top[] = {
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_TOP], level.bounds[SIDE_FRONT]},
      {level.bounds[SIDE_RIGHT], level.bounds[SIDE_TOP], level.bounds[SIDE_FRONT]},
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_TOP], level.bounds[SIDE_BACK]}
    };
    Vec3f bottom[] = {
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_BOTTOM], level.bounds[SIDE_BACK]},
      {level.bounds[SIDE_RIGHT], level.bounds[SIDE_BOTTOM], level.bounds[SIDE_BACK]},
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_BOTTOM], level.bounds[SIDE_FRONT]}
    };
    Vec3f front[] = {
      {level.bounds[SIDE_RIGHT], level.bounds[SIDE_TOP], level.bounds[SIDE_FRONT]},
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_TOP], level.bounds[SIDE_FRONT]},
      {level.bounds[SIDE_RIGHT], level.bounds[SIDE_BOTTOM], level.bounds[SIDE_FRONT]}
    };
    Vec3f back[] = {
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_TOP], level.bounds[SIDE_BACK]},
      {level.bounds[SIDE_RIGHT], level.bounds[SIDE_TOP], level.bounds[SIDE_BACK]},
      {level.bounds[SIDE_LEFT], level.bounds[SIDE_BOTTOM], level.bounds[SIDE_BACK]}
    };

    level.walls[SIDE_LEFT] = plane_from_points(left[0], left[1], left[2]);
    level.walls[SIDE_RIGHT] = plane_from_points(right[0], right[1], right[2]);
    level.walls[SIDE_TOP] = plane_from_points(top[0], top[1], top[2]);
    level.walls[SIDE_BOTTOM] = plane_from_points(bottom[0], bottom[1], bottom[2]);
    level.walls[SIDE_FRONT] = plane_from_points(front[0], front[1], front[2]);
    level.walls[SIDE_BACK] = plane_from_points(back[0], back[1], back[2]);
  }

  return level;
}

// Destroy a level and free its allocated memory
void level_destroy(Level* level) {
  free(level->bricks);
}
