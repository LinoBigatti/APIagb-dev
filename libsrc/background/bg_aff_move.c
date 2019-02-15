//Move an affine background.

#include <background/bg_aff_move.h>

void bg_aff_move(bg_affine *bg, int x, int y) {
	bg->x = x << 8;
	bg->y = y << 8;
}