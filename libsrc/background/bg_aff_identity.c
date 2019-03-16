//Set an affine matrix to the identity matrix.

#include <background/bg_aff_identity.h>

void bg_aff_identity(bg_affine *bg) {
	bg->pa = 1 << 8;
	bg->pd = 1 << 8;
	bg->pb = 0;
	bg->pc = 0;
}