//Draw an image on mode 4, using 16 bit units. (Not recommended)

#include <bitmap/mode4/m4_image_16.h>

void m4_image_16(const void *src_, u32 lenght) {
	u16 *dst = (u16*)m4_back_vram;
	u16 *src = (u16*)src_;
	
	for(int ii = 0; ii < lenght; ii++) {
		dst[ii] = src[ii];
	}
}