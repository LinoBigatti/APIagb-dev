//Rotate an affine background.

#ifndef BG_AFF_ROTATE_H
#define BG_AFF_ROTATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <basics/sin_cos.h>
#include <background/bg_defs.h>

extern void bg_aff_rotate(bg_affine *bg, u16 angle);

extern void bg_aff_rotate_inv(bg_affine *bg, u16 angle);

#ifdef __cplusplus
}
#endif

#endif
