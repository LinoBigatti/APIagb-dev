#include <basics/vsync.h>
#include <IO/regions.h>
#include <IO/options.h>
#include <bitmap/mode5/m5_image_32.h>
#include <bitmap/mode5/m5_flip.h>

#include "red_1.h"
#include "red_2.h"

int main(void) {
	int frames = 0;
	
	m5_flip();
	
	IO_DISPCNT = dispcnt_mode(5) | dispcnt_BG2;
	
	m5_image_32(red_1Bitmap, red_1BitmapLen/4);
	
	m5_flip();
	
	m5_image_32(red_2Bitmap, red_2BitmapLen/4);
	
	while(1) {
		Vsync();
		
		if(++frames == 30) { //Rudimentary Vsync timer.
			frames = 0;
			m5_flip();
		}
	}
	
	return 0;
}
