//Copy a map data using 32 bit units. (Recommended)

#include <background/bg_map_32.h>

void bg_map_32(const void *src_, u32 length, u32 sbb) {
	u32 *src = (u32*)src_;
	u32 *dst = (u32*)&se_memory[sbb][0];
	int ii;
	
	for(ii = 0; ii < length; ii++) {
		dst[ii] = src[ii];
	}
}