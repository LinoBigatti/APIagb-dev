//Load an object's tiles into VRAM, using 32 bit units. (Recommended)

#include <object/obj_tiles_32.h>

void obj_tiles_32(const void *src_, u32 length, u32 cb, u32 tile, u32 depth) {
	u32 *src = (u32*)src_;
	u32 *dst;
	if(depth == 4) {
		dst = (u32*)&tile_vram[cb][tile];
	} else {
		dst = (u32*)&tile8_vram[cb][tile];
	}
	int ii;
	
	for(ii = 0; ii < length; ii++) {
		dst[ii] = src[ii];
	}
}