//Scale an affine background.

#include <background/bg_aff_scale.h>

void bg_aff_scale(bg_affine *bg, int x, int y) {
	bg->pa = x << 8;
	bg->pb = 0;
	bg->pc = 0;
	bg->pd = y << 8;
}

void bg_aff_scale_inv(bg_affine *bg, int x, int y) {
	bg_aff_scale(bg, 1 / x, 1 / y);
}