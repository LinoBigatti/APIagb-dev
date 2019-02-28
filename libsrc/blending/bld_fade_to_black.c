//Fade to black.

#include <blending/bld_fade_to_black.h>

void bld_fade_to_black(void) {
	float alpha = 0;
	bldy_set(alpha);
	for(; alpha < 1.0; alpha += 0.01) {
		Vsync();
		bldy_set(alpha);
	}
}