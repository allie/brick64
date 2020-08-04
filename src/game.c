#include <nusys.h>
#include "common.h"
#include "game.h"
#include "graphics.h"
#include "camera.h"

#define ROT_VELOCITY 10.0f
#define MOVE_VELOCITY 0.5f

void game_init(void) {
  camera_init();
}

void game_update(void) {
  Vec2f rot;
  Vec3f velocity;
  vec2f_set(rot, 0, 0);
  vec3f_set(velocity, 0, 0, 0);

  // Rotate the camera if the C buttons are pressed
  if (nuContData[0].button & L_CBUTTONS) {
    rot.x = -1;
  }

  if (nuContData[0].button & R_CBUTTONS) {
    rot.x = 1;
  }

  if (nuContData[0].button & U_CBUTTONS) {
    rot.y = 1;
  }

  if (nuContData[0].button & D_CBUTTONS) {
    rot.y = -1;
  }

  if (fabs(rot.x) > EPSILON || fabs(rot.y) > EPSILON) {
    vec2f_mag(rot, ROT_VELOCITY);

    camera_rotate(rot);
  }

  // Move the camera if the joystick is moved
  if (nuContData[0].stick_y > DEADZONE || nuContData[0].stick_y < -DEADZONE) {
    velocity.z = nuContData[0].stick_y;
  }

  if (nuContData[0].stick_x > DEADZONE || nuContData[0].stick_x < -DEADZONE) {
    velocity.x = nuContData[0].stick_x;
  }

  if (fabs(velocity.z) > EPSILON || fabs(velocity.x) > EPSILON) {
    vec3f_norm(velocity);
    vec3f_mag(velocity, MOVE_VELOCITY);

    camera_move(velocity);
  }
}

void game_draw(void) {
  MVP* mvpp = &mvp[task_num];
  glistp = &glist[task_num][0];

  graphics_init_RCP();
  graphics_clear(100, 149, 237);

  camera_look(mvpp);

  graphics_draw_sphere();

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
