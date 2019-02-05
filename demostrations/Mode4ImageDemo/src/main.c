#include <basics/vsync.h>
#include <IO/regions.h>
#include <IO/options.h>
#include <bitmap/mode4/m4_image_32.h>
#include <bitmap/mode4/m4_palette_32.h>
#include <bitmap/mode4/m4_flip.h>

#include "mode4_0.h"
#include "mode4_1.h"
#include "mode4_2.h"
#include "mode4_3.h"
#include "mode4_4.h"
#include "mode4_5.h"
#include "mode4_6.h"
#include "mode4_7.h"
#include "mode4_8.h"
#include "mode4_9.h"
#include "mode4_10.h"

int ii, duration;

void load_next_frame(void) {
	switch(ii) {
		case 1 :
			m4_image_32(mode4_1Bitmap, mode4_1BitmapLen/4);
			duration = 25;
			break;
		
		case 2 :
			m4_image_32(mode4_2Bitmap, mode4_2BitmapLen/4);
			duration = 25;
			break;
		
		case 3 :
			m4_image_32(mode4_3Bitmap, mode4_3BitmapLen/4);
			duration = 25;
			break;
		
		case 4 :
			m4_image_32(mode4_4Bitmap, mode4_4BitmapLen/4);
			duration = 25;
			break;
		
		case 5 :
			m4_image_32(mode4_5Bitmap, mode4_5BitmapLen/4);
			duration = 25;
			break;
		
		case 6 :
			m4_image_32(mode4_6Bitmap, mode4_6BitmapLen/4);
			duration = 25;
			break;
		
		case 7 :
			m4_image_32(mode4_7Bitmap, mode4_7BitmapLen/4);
			duration = 25;
			break;
		
		case 8 :
			m4_image_32(mode4_8Bitmap, mode4_8BitmapLen/4);
			duration = 25;
			break;
		
		case 9 :
			m4_image_32(mode4_9Bitmap, mode4_9BitmapLen/4);
			duration = 25;
			break;
		
		case 10 :
			m4_image_32(mode4_10Bitmap, mode4_10BitmapLen/4);
			duration = 25;
			break;
		
		default :
			m4_image_32(mode4_0Bitmap, mode4_0BitmapLen/4);
			duration = 120;
			ii = 0;
			break;
	}
}
int main(void) {
	int frames = 0;
	ii = 2;
	duration = 25;
	
	m4_flip();
	
	IO_DISPCNT = dispcnt_mode(4) | dispcnt_BG2;
	
	m4_palette_32(SharedPal, SharedPalLen/4);
	
	m4_image_32(mode4_0Bitmap, mode4_0BitmapLen/4);
	
	m4_flip();
	
	m4_image_32(mode4_1Bitmap, mode4_1BitmapLen/4);
	
	while(1) {
		Vsync();
		
		if(++frames == duration) { //Rudimentary Vsync timer.
			ii += 1;
			frames = 0;
			m4_flip();
			load_next_frame();
		}
	}
	
	return 0;
}
