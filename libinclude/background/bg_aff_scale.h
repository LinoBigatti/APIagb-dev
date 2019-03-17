//Scale an affine background.

#ifndef BG_AFF_SCALE_H
#define BG_AFF_SCALE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <background/bg_defs.h>

extern void bg_aff_scale(bg_affine *bg, int x, int y);

extern void bg_aff_scale_inv(bg_affine *bg, int x, int y);

#ifdef __cplusplus
}
#endif

#endif
