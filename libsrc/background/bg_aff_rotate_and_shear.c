//Rotate and shear a background.

#include <background/bg_aff_rotate_and_shear.h>

void bg_aff_rotate_and_shear(bg_affine *bg, int x, int y, u16 angle) {
    int sin = fast_sin(angle);
	int cos = fast_cos(angle);
	
	int fOne = 1 << 8;
	
    bg->pa = ((cos * fOne) + (-sin * y)) >> 12;
	bg->pb = ((cos * x) + (-sin * fOne)) >> 12;
    bg->pc = ((sin * fOne) + (cos * y)) >> 12;
	bg->pd = ((sin * x) + (cos * fOne)) >> 12;
}

void bg_aff_rotate_and_shear_inv(bg_affine *bg, int x, int y, u16 angle) {
	bg_aff_rotate_and_shear(bg, -x, -y, -angle);
}