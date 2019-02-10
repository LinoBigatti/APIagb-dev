//Load an object's tiles into VRAM, using 16 bit units. (Not recommended)

#include <object/obj_tiles_16.h>

void obj_tiles_16(const void *src_, u32 length, u32 cb, u32 tile, u32 depth) {
	u16 *src = (u16*)src_;
	u16 *dst;
	if(depth == 4) {
		dst = (u16*)&tile_vram[cb][tile];
	} else {
		dst = (u16*)&tile8_vram[cb][tile];
	}
	int ii;
	
	for(ii = 0; ii < length; ii++) {
		dst[ii] = src[ii];
	}
}