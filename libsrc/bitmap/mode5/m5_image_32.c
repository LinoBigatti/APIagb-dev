//Draw an image on mode 3, using 32 bit units. (Recommended)

#include <bitmap/mode5/m5_image_32.h>

void m5_image_32(const void *src_, u32 lenght) {
	u32 *dst = (u32*)m5_back_vram;
	u32 *src= (u32*)src_;
	
	for(int ii = 0; ii<lenght; ii++) {
		dst[ii] = src[ii];
	}
}