#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <nusys.h>

#define SCREEN_W 320
#define SCREEN_H 240

#define GLIST_LENGTH 2048

Gfx glist[GLIST_LENGTH];
Gfx* glistp;

void graphics_init_RCP(Gfx *glistp);
void graphics_draw_rect(s32 x, s32 y, s32 w, s32 h, u8 r, u8 g, u8 b);
void graphics_clear_bg(u8 r, u8 g, u8 b);
void graphics_draw_sheep(void);

#endif
