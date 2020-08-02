#include <nusys.h>
#include "camera.h"
#include "graphics.h"

Camera camera;

void camera_init() {
  camera.pos.x = 0;
  camera.pos.y = 20;
  camera.pos.z = 50;
  camera.target.x = 0;
  camera.target.y = 0;
  camera.target.z = 0;
  camera.up.x = 0;
  camera.up.y = 1;
  camera.up.z = 0;
}

void camera_lookat_target(MVP* mvpp) {
  u16 persp_norm;

  // Initialize the projection matrix
  guPerspective(
    &mvpp->projection,
    &persp_norm,
    33,
    (float)SCREEN_W / (float)SCREEN_H,
    10,
    10000,
    1.0
  );
  gSPPerspNormalize(glistp++, persp_norm);

  // Initialize the model view matrix
  guLookAt(
    &mvpp->modelview,
    camera.pos.x, camera.pos.y, camera.pos.z,
    camera.target.x, camera.target.y, camera.target.z,
    camera.up.x, camera.up.y, camera.up.z
  );

  // Load the projection matrix into the matrix stack
  gSPMatrix(
    glistp++,
    OS_K0_TO_PHYSICAL(&(mvpp->projection)),
    G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH
  );

  // Load the model view matrix into the matrix stack
  gSPMatrix(
    glistp++,
    OS_K0_TO_PHYSICAL(&(mvpp->modelview)),
    G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH
  );
}