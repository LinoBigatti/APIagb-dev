//Rotate, scale and shear a background.

#ifndef BG_AFF_ROTATE_SCALE_AND_SHEAR_H
#define BG_AFF_ROTATE_SCALE_AND_SHEAR_H

#include <basics/types.h>
#include <basics/sin_cos.h>
#include <background/bg_defs.h>

extern void bg_aff_rotate_scale_and_shear(bg_affine *bg, int sx, int sy, int hx, int hy, u16 angle);

extern void bg_aff_rotate_scale_and_shear_inv(bg_affine *bg, int sx, int sy, int hx, int hy, u16 angle);

#endif