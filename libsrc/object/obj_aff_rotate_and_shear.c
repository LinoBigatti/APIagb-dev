//Rotate and shear an object.

#include <object/obj_aff_rotate_and_shear.h>

void obj_aff_rotate_and_shear(obj_affine *obj, int x, int y, u16 angle) {
    int sin = fast_sin(angle);
	int cos = fast_cos(angle);
	
	int fOne = 1 << 8;
	
    obj->pa = ((cos * fOne) + (-sin * y)) >> 12;
	obj->pb = ((cos * x) + (-sin * fOne)) >> 12;
    obj->pc = ((sin * fOne) + (cos * y)) >> 12;
	obj->pd = ((sin * x) + (cos * fOne)) >> 12;
}

void obj_aff_rotate_and_shear_inv(obj_affine *obj, int x, int y, u16 angle) {
	obj_aff_rotate_and_shear(obj, -x, -y, -angle);
}