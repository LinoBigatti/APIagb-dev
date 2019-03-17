//Rotate an affine object.

#ifndef OBJ_AFF_ROTATE_H
#define OBJ_AFF_ROTATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <basics/sin_cos.h>
#include <object/obj_defs.h>

extern void obj_aff_rotate(obj_affine *obj, u16 angle);

extern void obj_aff_rotate_inv(obj_affine *obj, u16 angle);

#ifdef __cplusplus
}
#endif

#endif
