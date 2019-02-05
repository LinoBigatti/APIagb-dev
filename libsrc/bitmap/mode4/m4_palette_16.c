//Load a palette into mode 4, using 16 bits units. (Not recommended)

#include <bitmap/mode4/m4_palette_16.h>

void m4_palette_16(const void *src_, u32 length) {
	u16 *dst = (u16*)m4_pal_memory;
	u16 *src = (u16*)src_;
	
	for(int ii = 0; ii < length; ii++) {
		dst[ii] = src[ii];
	}
}