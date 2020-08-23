#include "brick.h"

void brick_update(Brick* brick, double dt) {
  // Tick down death animation timer if it's running
  if (brick->lives == 0 && brick->death_anim_timer > 0) {
    brick->death_anim_timer -= dt;

    if (brick->death_anim_timer < 0) {
      brick->death_anim_timer = 0;
    }

    brick->obj.scale = (brick->death_anim_timer / BRICK_DEATH_ANIM_DURATION);
  }

  // Tick down hit animation timer if it's running
  if (brick->hit_anim_timer > 0) {
    brick->hit_anim_timer -= dt;

    if (brick->hit_anim_timer < 0) {
      brick->hit_anim_timer = 0;
    }

    vec3f_set(
      brick->obj.rot,
      sin(2 * M_PI * ((BRICK_HIT_ANIM_DURATION - brick->hit_anim_timer) / BRICK_HIT_ANIM_DURATION)) * 10.0,
      0,
      sin(4 * M_PI * ((BRICK_HIT_ANIM_DURATION - brick->hit_anim_timer) / BRICK_HIT_ANIM_DURATION)) * 6.0
    );
  }
}
