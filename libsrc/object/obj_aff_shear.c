//Shear an affine object.

#include <object/obj_aff_shear.h>

void obj_aff_shear(obj_affine *obj, int x, int y) {
	obj->pa = 1 << 8;
	obj->pb = x;
	obj->pc = y;
	obj->pd = 1 << 8;
}

void obj_aff_shear_inv(obj_affine *obj, int x, int y) {
	obj_aff_shear(obj, -x, -y);
}