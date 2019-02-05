//Load a palette into mode 4, using 32 bits units. (Recommended)

#include <bitmap/mode4/m4_palette_32.h>

void m4_palette_32(const void *src_, u32 length) {
	u32 *dst = (u32*)m4_pal_memory;
	u32 *src = (u32*)src_;
	
	for(int ii = 0; ii < length; ii++) {
		dst[ii] = src[ii];
	}
}