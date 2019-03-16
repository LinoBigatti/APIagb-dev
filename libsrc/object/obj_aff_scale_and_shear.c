//Scale and shear an object.

#include <object/obj_aff_scale_and_shear.h>

void obj_aff_scale_and_shear(obj_affine *obj, int sx, int sy, int hx, int hy) {
	int fOne = 1 << 8;
	
    obj->pa = ((sx * fOne) + (0 * hy)) >> 8;
	obj->pb = ((sx * hx) + (0 * fOne)) >> 8;
    obj->pc = ((0 * fOne) + (sy * hy)) >> 8;
	obj->pd = ((0 * hx) + (sy * fOne)) >> 8;
}

void obj_aff_scale_and_shear_inv(obj_affine *obj, int sx, int sy, int hx, int hy) {
	obj_aff_scale_and_shear(obj, 1 / sx, 1 / sy, -hx, -hy);
}