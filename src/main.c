#include <nusys.h>
#include "game.h"

static void vsync_callback(int pending) {
  game_update();

  if (pending < 1) {
    game_draw();
  }
}

void mainproc(void* dummy) {
  nuGfxInit();
  nuContInit();

  game_init();

  nuGfxFuncSet((NUGfxFunc)vsync_callback);
  nuGfxDisplayOn();

  while (1);
}
