#include <basics/vsync.h>
#include <IO/regions.h>
#include <IO/options.h>
#include <bitmap/mode3/m3_image_32.h>

#include "demo.h"

int main(void) {
	IO_DISPCNT = dispcnt_mode(3) | dispcnt_BG2;
	
	m3_image_32(demoBitmap, demoBitmapLen/4);
	
	while(1) {
		Vsync();
	}
	
	return 0;
}
