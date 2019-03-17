//Shear an affine background.

#ifndef BG_AFF_SHEAR_H
#define BG_AFF_SHEAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <background/bg_defs.h>

extern void bg_aff_shear(bg_affine *bg, int x, int y);

extern void bg_aff_shear_inv(bg_affine *bg, int x, int y);

#ifdef __cplusplus
}
#endif

#endif
