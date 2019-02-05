//Fill the entire mode 4.

#include <bitmap/mode4/m4_fill.h>

void m4_fill(m4_color_entry clr_) {
	u32 *dst = (u32*)m4_back_vram;
	u32 clr = clr_ | (clr_ << 8) | (clr_ << 16) | (clr_ << 24);
	int ii = 0;
	
	for(; ii < (M4_WIDTH * M4_HEIGHT) / 4; ii++) {
		dst[ii] = clr;
	}
}