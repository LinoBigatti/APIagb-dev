//Apply normal blending.

#include <blending/bld_set.h>

void bld_set(float alpha) {
	u32 alpha_fix = alpha * 16;
	if(alpha_fix > 16) { alpha_fix = 16; }
	IO_BLDALPHA = alpha_fix | ((16 - alpha_fix) << 8);
}