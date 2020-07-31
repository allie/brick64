#include <nusys.h>
#include "graphics.h"

static Vp viewport = {
  SCREEN_W * 2, SCREEN_H * 2, G_MAXZ, 0,
  SCREEN_W * 2, SCREEN_H * 2, G_MAXZ, 0
};

static Gfx rsp_init[] = {
  gsSPViewport(&viewport),
  gsSPClearGeometryMode(G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH |
                        G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                        G_TEXTURE_GEN_LINEAR | G_LOD),
  gsSPTexture(0, 0, 0, 0, G_OFF),
  gsSPEndDisplayList()
};

static Gfx rdp_init[] = {
  gsDPSetCycleType(G_CYC_1CYCLE),
  gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_W, SCREEN_H),
  gsDPSetCombineKey(G_CK_NONE),
  gsDPSetAlphaCompare(G_AC_NONE),
  gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
  gsDPSetColorDither(G_CD_DISABLE),
  gsDPPipeSync(),
  gsSPEndDisplayList()
};

void graphics_init_RCP(Gfx *glistp) {
  // Set the segment register
  gSPSegment(glistp++, 0, 0);

  // Execute RSP display list
  gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rsp_init));

  // Execute RDP display list
  gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rdp_init));
}

void graphics_clear_bg(u8 r, u8 g, u8 b) {
  gDPSetCycleType(glistp++, G_CYC_FILL);
  gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_W, osVirtualToPhysical(nuGfxCfb_ptr));
  gDPSetFillColor(glistp++, (GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1)));
  gDPFillRectangle(glistp++, 0, 0, SCREEN_W - 1, SCREEN_H - 1);
  gDPPipeSync(glistp++);
}

void graphics_draw_rect(s32 x, s32 y, s32 w, s32 h, u8 r, u8 g, u8 b) {
  gDPSetFillColor(glistp++, (GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1)));
  gDPFillRectangle(glistp++, x, y, x + w, y + h);
  gDPPipeSync(glistp++);
}
