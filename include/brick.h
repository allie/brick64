#ifndef BRICK_H
#define BRICK_H

#include "common.h"
#include "vector.h"
#include "object.h"

// Length of a side
#define BRICK_W UNIT_SIZE

// Half length of a side
#define BRICK_R (UNIT_SIZE / 2)

// Radius of the sphere that circumscribes a brick
#define BRICK_CR (BRICK_W * 1.2247449f)

// Animation parameters
#define BRICK_DEATH_ANIM_DURATION 0.1
#define BRICK_HIT_ANIM_DURATION 0.1

typedef struct {
  Vec3f left[4];
  Vec3f right[4];
  Vec3f top[4];
  Vec3f bottom[4];
  Vec3f front[4];
  Vec3f back[4];
  u8 lives;
  Object obj;
  double death_anim_timer;
  double hit_anim_timer;
} Brick;

void brick_update(Brick* brick, double dt);

#endif
