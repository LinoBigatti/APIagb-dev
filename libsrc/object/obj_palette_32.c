//Load an object's palette, using 32 bit units. (Recommended)

#include <object/obj_palette_32.h>

void obj_palette_32(const void *src_, u32 length, u32 palbank) {
	u32 *src = (u32*)src_;
	u32 *dst;
	if(length == 8) {
		dst = (u32*)&obj_pal_memory[8 * palbank];
	} else {
		dst = (u32*)&obj_pal_memory[0];
	}
	int ii;
	
	for(ii = 0; ii < length; ii++) {
		dst[ii] = src[ii];
	}
}