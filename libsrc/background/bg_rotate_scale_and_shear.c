//Rotate, scale and shear a background.

#include <background/bg_aff_rotate_scale_and_shear.h>

void bg_aff_rotate_scale_and_shear(bg_affine *bg, int sx, int sy, int hx, int hy, u16 angle) {
	int sin = fast_sin(angle);
	int cos = fast_cos(angle);
	
	int fOne = 1 << 8;
	
    int pa = ((sx * fOne) + (0 * hy)) >> 8;
	int pb = ((sx * hx) + (0 * fOne)) >> 8;
    int pc = ((0 * fOne) + (sy * hy)) >> 8;
	int pd = ((0 * hx) + (sy * fOne)) >> 8;
	
	bg->pa = ((cos * pa) + (-sin * pc)) >> 12;
	bg->pb = ((cos * pb) + (-sin * pd)) >> 12;
    bg->pc = ((sin * pa) + (cos * pc)) >> 12;
	bg->pd = ((sin * pb) + (cos * pd)) >> 12;
}

void bg_aff_rotate_scale_and_shear_inv(bg_affine *bg, int sx, int sy, int hx, int hy, u16 angle) {
	bg_aff_rotate_scale_and_shear(bg, 1 / sx, 1 / sy, -hx, -hy, -angle);
}