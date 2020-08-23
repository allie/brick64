#ifndef PADDLE_H
#define PADDLE_H

#include "common.h"
#include "object.h"
#include "vector.h"
#include "level.h"

// Paddle width
#define PADDLE_W 400

// Paddle half width
#define PADDLE_R (PADDLE_W / 2)

// Base movement speed
#define PADDLE_BASE_VELOCITY (350.0 * 5)

// Animation parameters
#define PADDLE_HIT_ANIM_DURATION 0.2
#define PADDLE_HIT_ANIM_INTENSITY 20.0f

typedef struct {
  Object obj;
  double hit_anim_timer;
  Vec3f hit_rot;
  bool held;
  Vec3f hold_pos;
  float min_x, max_x, min_y, max_y;
} Paddle;

void paddle_init(Paddle* paddle, Level* level);
void paddle_update(Paddle* paddle, Level* level, double dt);

#endif
