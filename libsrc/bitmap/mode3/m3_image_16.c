//Draw an image on mode 3, using 32 bit units. (Not recommended)

#include <bitmap/mode3/m3_image_16.h>

void m3_image_16(const void *src_, u32 lenght) {
	u16 *dst = (u16*)m3_vram;
	u16 *src= (u16*)src_;
	
	for(int ii = 0; ii<lenght; ii++) {
		dst[ii] = src[ii];
	}
}