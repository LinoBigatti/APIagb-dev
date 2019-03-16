//Rotate an affine object.

#include <object/obj_aff_rotate.h>

void obj_aff_rotate(obj_affine *obj, u16 angle) {
	int sin = fast_sin(angle) >> 4;
	int cos = fast_cos(angle) >> 4;
	
	obj->pa = cos;
	obj->pb = -sin;
	obj->pc = sin;
	obj->pd = cos;
}

void obj_aff_rotate_inv(obj_affine *obj, u16 angle) {
	obj_aff_rotate(obj, -angle);
}