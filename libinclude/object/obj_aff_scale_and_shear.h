//Scale and shear an object.

#ifndef OBJ_AFF_SCALE_AND_SHEAR_H
#define OBJ_AFF_SCALE_AND_SHEAR_H

#include <object/obj_defs.h>

extern void obj_aff_scale_and_shear(obj_affine *obj, int sx, int sy, int hx, int hy);

extern void obj_aff_scale_and_shear_inv(obj_affine *obj, int sx, int sy, int hx, int hy);

#endif