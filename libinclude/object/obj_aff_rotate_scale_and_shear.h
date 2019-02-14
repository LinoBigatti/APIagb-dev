//Rotate, scale and shear an object.

#ifndef OBJ_AFF_ROTATE_SCALE_AND_SHEAR_H
#define OBJ_AFF_ROTATE_SCALE_AND_SHEAR_H

#include <basics/types.h>
#include <basics/sin_cos.h>
#include <object/obj_defs.h>

extern void obj_aff_rotate_scale_and_shear(obj_affine *obj, int sx, int sy, int hx, int hy, u16 angle);

extern void obj_aff_rotate_scale_and_shear_inv(obj_affine *obj, int sx, int sy, int hx, int hy, u16 angle);

#endif