#include <nusys.h>
#include "game.h"
#include "graphics.h"
#include "camera.h"

#define MAX_ZOOM 100.0f
#define MIN_ZOOM 5.0f

static float zoom;
static float rot;
static float cx;
static float cz;

void game_init(void) {
  zoom = 25.0f;
  rot = 0.0f;
  cx = 0.0f;
  cz = 0.0f;

  camera_init();
}

void game_update(void) {
  if (nuContData[0].stick_y > 50) {
    zoom -= 1.0f;
  }

  if (nuContData[0].stick_y < -50) {
    zoom += 1.0f;
  }

  if (zoom > MAX_ZOOM) {
    zoom = MAX_ZOOM;
  }

  if (zoom < MIN_ZOOM) {
    zoom = MIN_ZOOM;
  }

  cx = sinf(rot) * zoom;
  cz = cosf(rot) * zoom;

  rot += 0.025f;
}

void game_draw(void) {
  MVP* mvpp = &mvp[task_num];
  glistp = &glist[task_num][0];

  graphics_init_RCP();
  graphics_clear(100, 149, 237);

  camera.pos.x = cx;
  camera.pos.z = cz;
  camera_lookat_target(mvpp);

  graphics_draw_model();

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
