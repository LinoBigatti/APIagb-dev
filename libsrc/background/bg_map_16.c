//Copy a map data using 16 bit units. (Not recommended)

#include <background/bg_map_16.h>

void bg_map_16(const void *src_, u32 length, u32 sbb) {
	u16 *src = (u16*)src_;
	u16 *dst = (u16*)&se_memory[sbb][0];
	int ii;
	
	for(ii = 0; ii < length; ii++) {
		dst[ii] = src[ii];
	}
}