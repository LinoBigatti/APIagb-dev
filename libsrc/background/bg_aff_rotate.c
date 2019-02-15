//Rotate an affine background.

#include <background/bg_aff_rotate.h>

void bg_aff_rotate(bg_affine *bg, u16 angle) {
	int sin = fast_sin(angle) >> 4;
	int cos = fast_cos(angle) >> 4;
	
	bg->pa = cos;
	bg->pb = -sin;
	bg->pc = sin;
	bg->pd = cos;
}

void bg_aff_rotate_inv(bg_affine *bg, u16 angle) {
	bg_aff_rotate(bg, -angle);
}