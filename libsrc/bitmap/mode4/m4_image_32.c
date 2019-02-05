//Draw an image on mode 4, using 32 bit units. (Recommended)

#include <bitmap/mode4/m4_image_32.h>

void m4_image_32(const void *src_, u32 lenght) {
	u32 *dst = (u32*)m4_back_vram;
	u32 *src = (u32*)src_;
	
	for(int ii = 0; ii < lenght; ii++) {
		dst[ii] = src[ii];
	}
}