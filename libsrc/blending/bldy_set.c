//Apply white/black blending.

#include <blending/bldy_set.h>

void bldy_set(float alpha) {
	u32 alpha_fix = alpha * 16;
	if(alpha_fix > 16) { alpha_fix = 16; }
	IO_BLDY = alpha_fix;
}