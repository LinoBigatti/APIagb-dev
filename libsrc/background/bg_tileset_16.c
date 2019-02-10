//Copy a tileset to the VRAM, using 16 bit units. (Not recommended)

#include <background/bg_tileset_16.h>

void bg_tileset_16(const void *src_, u32 length, u32 cbb, u32 depth) {
	u16 *src = (u16*)src_;
	u16 *dst;
	if(depth == 4) {
		dst = (u16*)&tile_vram[cbb][0];
	} else {
		dst = (u16*)&tile8_vram[cbb][0];
	}
	int ii;
	
	for(ii = 0; ii < length; ii++) {
		dst[ii] = src[ii];
	}
}