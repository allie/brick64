#ifndef LEVEL_H
#define LEVEL_H

#include "common.h"
#include "brick.h"
#include "plane.h"

#define MAX_BRICKS 125

typedef struct {
  double start_vel;
  int width;
  int height;
  int depth;
  u8 bricks[MAX_BRICKS];
} LevelData;

typedef struct {
  double start_vel;
  int width;
  int height;
  int depth;
  int num_bricks;
  Plane walls[6];
  float bounds[6];
  Brick* bricks;
} Level;

// Load a level from the given data
Level level_load(LevelData* data);

// Destroy a level and free its allocated memory
void level_destroy(Level* level);

#endif
