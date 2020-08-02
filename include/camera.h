#ifndef CAMERA_H
#define CAMERA_H

#include <nusys.h>
#include "common.h"
#include "graphics.h"

typedef struct {
  Vec3f pos;
  Vec3f target;
  Vec3f up;
} Camera;

extern Camera camera;

void camera_init();
void camera_lookat_target(MVP* mvpp);

#endif
