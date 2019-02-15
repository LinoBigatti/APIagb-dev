//Scale and shear a background.

#include <background/bg_aff_scale_and_shear.h>

void bg_aff_scale_and_shear(bg_affine *bg, int sx, int sy, int hx, int hy) {
	int fOne = 1 << 8;
	
    bg->pa = ((sx * fOne) + (0 * hy)) >> 8;
	bg->pb = ((sx * hx) + (0 * fOne)) >> 8;
    bg->pc = ((0 * fOne) + (sy * hy)) >> 8;
	bg->pd = ((0 * hx) + (sy * fOne)) >> 8;
}

void bg_aff_scale_and_shear_inv(bg_affine *bg, int sx, int sy, int hx, int hy) {
	bg_aff_scale_and_shear(bg, 1 / sx, 1 / sy, -hx, -hy);
}