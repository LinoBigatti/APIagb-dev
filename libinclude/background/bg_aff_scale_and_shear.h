//Scale and shear a background.

#ifndef BG_AFF_SCALE_AND_SHEAR_H
#define BG_AFF_SCALE_AND_SHEAR_H

#include <background/bg_defs.h>

extern void bg_aff_scale_and_shear(bg_affine *bg, int sx, int sy, int hx, int hy);

extern void bg_aff_scale_and_shear_inv(bg_affine *bg, int sx, int sy, int hx, int hy);

#endif