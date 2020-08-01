#include <nusys.h>
#include "game.h"
#include "graphics.h"

static u8 r;
static u8 g;
static u8 b;

static int x, xdir;
static int y, ydir;

void game_init(void) {
  r = 0;
  g = 0;
  b = 0;
  x = 0;
  y = 0;
  xdir = 1;
  ydir = 1;
}

void game_update(void) {
  r++;
  g += 4;
  b += 7;

  x += 3 * xdir;
  y += 3 * ydir;

  if ((y + 32 >= SCREEN_H) || (y <= 0)) {
    ydir *= -1;
  }

  if ((x + 32 >= SCREEN_W) || (x <= 0)) {
    xdir *= -1;
  }
}

void game_draw(void) {
  glistp = glist;

  graphics_init_RCP(glistp);
  graphics_clear_bg(r, g, b);
  graphics_draw_rect(x, y, 32, 32, 255 - r, 255 - g, 255 - b);
  graphics_draw_sheep();
  gDPFullSync(glistp++);
  gSPEndDisplayList(glistp++);

  nuGfxTaskStart(glist, (s32)(glistp - glist) * sizeof(Gfx), NU_GFX_UCODE_F3DEX, NU_SC_SWAPBUFFER);
}
