//Fade to white.

#include <blending/bld_fade_to_white.h>

void bld_fade_to_white(void) {
	float alpha = 0;
	bldy_set(alpha);
	for(; alpha < 1.0; alpha += 0.01) {
		Vsync();
		bldy_set(alpha);
	}
}