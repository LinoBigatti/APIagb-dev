//Scale an affine object.

#ifndef OBJ_AFF_SCALE_H
#define OBJ_AFF_SCALE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <object/obj_defs.h>

extern void obj_aff_scale(obj_affine *obj, int x, int y);

extern void obj_aff_scale_inv(obj_affine *obj, int x, int y);

#ifdef __cplusplus
}
#endif

#endif
