//Shear an affine background.

#include <background/bg_aff_shear.h>

void bg_aff_shear(bg_affine *bg, int x, int y) {
	bg->pa = 1 << 8;
	bg->pb = x;
	bg->pc = y;
	bg->pd = 1 << 8;
}

void bg_aff_shear_inv(bg_affine *bg, int x, int y) {
	bg_aff_shear(bg, -x, -y);
}