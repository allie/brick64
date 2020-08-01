#include <nusys.h>
#include "graphics.h"

#include "models/cube.h"

MVP mvp[MAX_TASKS];
Gfx glist[MAX_TASKS][GLIST_LENGTH];
Gfx* glistp;
u32 task_num = 0;

static Vp viewport = {
  SCREEN_W * 2, SCREEN_H * 2, G_MAXZ, 0,
  SCREEN_W * 2, SCREEN_H * 2, G_MAXZ, 0
};

static Gfx rsp_init_dl[] = {
  gsSPViewport(&viewport),
  gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH | G_LIGHTING),
  gsSPTexture(0, 0, 0, 0, G_OFF),
  gsSPEndDisplayList()
};

static Gfx rdp_init_dl[] = {
  gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_W, SCREEN_H),
  gsDPSetColorDither(G_CD_BAYER),
  gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
  gsDPPipeSync(),
  gsSPEndDisplayList()
};

// Initialize RCP
void graphics_init_RCP() {
  gSPSegment(glistp++, 0, 0);
  gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rsp_init_dl));
  gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rdp_init_dl));
}

void graphics_clear(u8 r, u8 g, u8 b) {
  // Clear Z buffer
  gDPSetDepthImage(glistp++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
  gDPPipeSync(glistp++);
  gDPSetCycleType(glistp++, G_CYC_FILL);
  gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_W, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
  gDPSetFillColor(glistp++, (GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0)));
  gDPFillRectangle(glistp++, 0, 0, SCREEN_W - 1, SCREEN_H - 1);
  gDPPipeSync(glistp++);

  // Clear frame buffer
  gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_W, osVirtualToPhysical(nuGfxCfb_ptr));
  gDPSetFillColor(glistp++, (GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1)));
  gDPFillRectangle(glistp++, 0, 0, SCREEN_W - 1, SCREEN_H - 1);
  gDPPipeSync(glistp++);
}

void graphics_draw_model(void) {
  gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(model_dl_opaque));
}
