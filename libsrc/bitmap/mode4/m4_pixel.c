//Plot a pixel on mode 4.

#include <bitmap/mode4/m4_pixel.h>

void m4_pixel(u32 x, u32 y, m4_color_entry clr) {
	u16 *dst = &m4_back_vram[(x + y * M4_WIDTH) / 2];
	
	if(x & 1) { //X is even
		*dst = (*dst & 0xFF00) | clr;
	} else { //X is odd
		*dst = (*dst & 0x00FF) | (clr << 8);
	}
}