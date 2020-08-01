#include <nusys.h>
#include "graphics.h"

void camera_set_view_mtx(MVP* mvpp, float xv, float yv, float zv, float xl, float yl, float zl) {
  u16 persp_norm;
  LookAt lookat;

  guPerspective(
    &mvpp->projection,
    &persp_norm,
    33,
    (float)SCREEN_W / (float)SCREEN_H,
    10,
    10000,
    1.0
  );

  guLookAtReflect(
    &mvpp->view,
    &lookat,
    xv, yv, zv,
    xl, yl, zl,
    0, 1, 0
  );

  gSPPerspNormalize(glistp++, persp_norm);
  gSPLookAt(glistp++, &lookat);

  gSPMatrix(
    glistp++,
    &(mvpp->projection),
    G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH
  );

  gSPMatrix(
    glistp++,
    &(mvpp->view),
    G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH
  );
}