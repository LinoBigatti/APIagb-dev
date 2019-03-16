//Copy a tileset to the VRAM, using 32 bit units. (Recommended)

#include <background/bg_tileset_32.h>

void bg_tileset_32(const void *src_, u32 length, u32 cbb, u32 depth) {
	u32 *src = (u32*)src_;
	u32 *dst;
	if(depth == 4) {
		dst = (u32*)&tile_vram[cbb][0];
	} else {
		dst = (u32*)&tile8_vram[cbb][0];
	}
	int ii;
	
	for(ii = 0; ii < length; ii++) {
		dst[ii] = src[ii];
	}
}