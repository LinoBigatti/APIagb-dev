//Rotate and shear an object.

#ifndef OBJ_AFF_ROTATE_AND_SHEAR_H
#define OBJ_AFF_ROTATE_AND_SHEAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <basics/sin_cos.h>
#include <object/obj_defs.h>

void obj_aff_rotate_and_shear(obj_affine *obj, int x, int y, u16 angle);

void obj_aff_rotate_and_shear_inv(obj_affine *obj, int x, int y, u16 angle);

#ifdef __cplusplus
}
#endif

#endif
