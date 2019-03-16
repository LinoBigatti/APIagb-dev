//Rotate and scale an object.

#include <object/obj_aff_rotate_and_scale.h>

void obj_aff_rotate_and_scale(obj_affine *obj, int x, int y, u16 angle) {
    int sin = fast_sin(angle);
	int cos = fast_cos(angle);
	
    obj->pa = ((cos * x) + (-sin * 0)) >> 12;
	obj->pb = ((cos * 0) + (-sin * y)) >> 12;
    obj->pc = ((sin * x) + (cos * 0)) >> 12;
	obj->pd = ((sin * 0) + (cos * y)) >> 12;
}

void obj_aff_rotate_and_scale_inv(obj_affine *obj, int x, int y, u16 angle) {
	obj_aff_rotate_and_scale(obj, 1 / x, 1 / y, -angle);
}