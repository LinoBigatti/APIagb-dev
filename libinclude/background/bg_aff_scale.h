//Scale an affine background.

#ifndef BG_AFF_SCALE_H
#define BG_AFF_SCALE_H

#include <background/bg_defs.h>

extern void bg_aff_scale(bg_affine *bg, int x, int y);

extern void bg_aff_scale_inv(bg_affine *bg, int x, int y);

#endif