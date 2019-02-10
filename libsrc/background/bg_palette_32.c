//Load a map's palette, using 32 bit units. (Recommended)

#include <background/bg_palette_32.h>

void bg_palette_32(const void *src_, u32 length, u32 palbank) {
	u32 *src = (u32*)src_;
	u32 *dst;
	if(length == 8) {
		dst = (u32*)&bg_pal_memory[8 * palbank];
	} else {
		dst = (u32*)&bg_pal_memory[0];
	}
	int ii;
	
	for(ii = 0; ii < 8; ii++) {
		dst[ii] = src[ii];
	}
}