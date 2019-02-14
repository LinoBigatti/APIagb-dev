//Scale an affine object.

#include <object/obj_aff_scale.h>

void obj_aff_scale(obj_affine *obj, int x, int y) {
	obj->pa = x << 8;
	obj->pb = 0;
	obj->pc = 0;
	obj->pd = y << 8;
}

void obj_aff_scale_inv(obj_affine *obj, int x, int y) {
	obj_aff_scale(obj, 1 / x, 1 / y);
}