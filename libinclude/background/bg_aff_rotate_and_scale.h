//Rotate and scale a background.

#ifndef BG_AFF_ROTATE_AND_SCALE_H
#define BG_AFF_ROTATE_AND_SCALE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <basics/sin_cos.h>
#include <background/bg_defs.h>

void bg_aff_rotate_and_scale(bg_affine *bg, int x, int y, u16 angle);

void bg_aff_rotate_and_scale_inv(bg_affine *bg, int x, int y, u16 angle);

#ifdef __cplusplus
}
#endif

#endif
