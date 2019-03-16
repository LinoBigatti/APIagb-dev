//Rotate and scale a background.

#include <background/bg_aff_rotate_and_scale.h>

void bg_aff_rotate_and_scale(bg_affine *bg, int x, int y, u16 angle) {
    int sin = fast_sin(angle);
	int cos = fast_cos(angle);
	
    bg->pa = ((cos * x) + (-sin * 0)) >> 12;
	bg->pb = ((cos * 0) + (-sin * y)) >> 12;
    bg->pc = ((sin * x) + (cos * 0)) >> 12;
	bg->pd = ((sin * 0) + (cos * y)) >> 12;
}

void bg_aff_rotate_and_scale_inv(bg_affine *bg, int x, int y, u16 angle) {
	bg_aff_rotate_and_scale(bg, 1 / x, 1 / y, -angle);
}