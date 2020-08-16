#ifndef COMMON_H
#define COMMON_H

#include <math.h>
#include <nusys.h>

#define EPSILON 0.00001f

#define DEADZONE 10

#define radians(d) ((d) * M_PI / 180.0)
#define degrees(r) ((r) * 180.0 / M_PI)

typedef u32 bool;

#endif
