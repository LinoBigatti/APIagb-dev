//Fill the entire mode 5.

#include <bitmap/mode5/m5_fill.h>

void m5_fill(m5_color clr_) {
	u32 *dst = (u32*)m5_back_vram;
	u32 clr = clr_ | (clr_ << 16);
	int ii = 0;
	
	for(; ii < (M5_WIDTH * M5_HEIGHT) / 2; ii++) {
		dst[ii] = clr;
	}
}