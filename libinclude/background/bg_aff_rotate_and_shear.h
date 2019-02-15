//Rotate and shear a background.

#ifndef BG_AFF_ROTATE_AND_SHEAR_H
#define BG_AFF_ROTATE_AND_SHEAR_H

#include <basics/types.h>
#include <basics/sin_cos.h>
#include <background/bg_defs.h>

void bg_aff_rotate_and_shear(bg_affine *bg, int x, int y, u16 angle);

void bg_aff_rotate_and_shear_inv(bg_affine *bg, int x, int y, u16 angle);

#endif