//Rotate, scale and shear an object.

#include <object/obj_aff_rotate_scale_and_shear.h>

void obj_aff_rotate_scale_and_shear(obj_affine *obj, int sx, int sy, int hx, int hy, u16 angle) {
	int sin = fast_sin(angle);
	int cos = fast_cos(angle);
	
	int fOne = 1 << 8;
	
    int pa = ((sx * fOne) + (0 * hy)) >> 8;
	int pb = ((sx * hx) + (0 * fOne)) >> 8;
    int pc = ((0 * fOne) + (sy * hy)) >> 8;
	int pd = ((0 * hx) + (sy * fOne)) >> 8;
	
	obj->pa = ((cos * pa) + (-sin * pc)) >> 12;
	obj->pb = ((cos * pb) + (-sin * pd)) >> 12;
    obj->pc = ((sin * pa) + (cos * pc)) >> 12;
	obj->pd = ((sin * pb) + (cos * pd)) >> 12;
}

void obj_aff_rotate_scale_and_shear_inv(obj_affine *obj, int sx, int sy, int hx, int hy, u16 angle) {
	obj_aff_rotate_scale_and_shear(obj, 1 / sx, 1 / sy, -hx, -hy, -angle);
}