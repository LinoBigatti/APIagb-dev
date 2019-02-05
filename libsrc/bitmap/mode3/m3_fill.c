//Fill the entire mode 3.

#include <bitmap/mode3/m3_fill.h>

void m3_fill(m3_color clr_) {
	u32 *dst = (u32*)m3_vram;
	u32 clr = clr_ | (clr_ << 16);
	int ii = 0;
	
	for(; ii < (M3_WIDTH * M3_HEIGHT) / 2; ii++) {
		dst[ii] = clr;
	}
}