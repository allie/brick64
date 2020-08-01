#include <nusys.h>
#include "game.h"

void vsyncCallback(int pending) {
  game_update();

  if (pending < 1) {
    game_draw();
  }
}

void mainproc(void* dummy) {
  nuGfxInit();
  nuContInit();

  game_init();

  nuGfxFuncSet((NUGfxFunc)vsyncCallback);
  nuGfxDisplayOn();

  while (1);
}
