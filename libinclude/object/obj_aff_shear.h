//Shear an affine object.

#ifndef OBJ_AFF_SHEAR_H
#define OBJ_AFF_SHEAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <object/obj_defs.h>

extern void obj_aff_shear(obj_affine *obj, int x, int y);

extern void obj_aff_shear_inv(obj_affine *obj, int x, int y);

#ifdef __cplusplus
}
#endif

#endif
