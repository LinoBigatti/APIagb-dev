#include <basics/vsync.h>
#include <IO/regions.h>
#include <IO/options.h>
#include <bitmap/mode4/m4_image_32.h>
#include <bitmap/mode4/m4_palette_32.h>
#include <bitmap/mode4/m4_flip.h>
#include <input.h>

#include "ButtonA.h"
#include "ButtonB.h"
#include "ButtonSelect.h"
#include "ButtonStart.h"
#include "ButtonUp.h"
#include "ButtonDown.h"
#include "ButtonRight.h"
#include "ButtonLeft.h"
#include "ButtonR.h"
#include "ButtonL.h"
#include "Default.h"

int main(void) {
	m4_flip();
	
	IO_DISPCNT = dispcnt_mode(4) | dispcnt_BG2;
	
	m4_palette_32(SharedPal, SharedPalLen/4);
	
	m4_image_32(DefaultBitmap, DefaultBitmapLen/4);
	
	m4_flip();
	
	while(1) {
		Vsync();
		
		key_update();
		
		if(key_start_pressing(BUTTON_A)) {
			m4_image_32(ButtonABitmap, ButtonABitmapLen/4);
			m4_flip();
		} else if(key_start_pressing(BUTTON_B)) {
			m4_image_32(ButtonBBitmap, ButtonBBitmapLen/4);
			m4_flip();
		} else if(key_start_pressing(BUTTON_SELECT)) {
			m4_image_32(ButtonSelectBitmap, ButtonSelectBitmapLen/4);
			m4_flip();
		} else if(key_start_pressing(BUTTON_START)) {
			m4_image_32(ButtonStartBitmap, ButtonStartBitmapLen/4);
			m4_flip();
		} else if(key_start_pressing(BUTTON_UP)) {
			m4_image_32(ButtonUpBitmap, ButtonUpBitmapLen/4);
			m4_flip();
		} else if(key_start_pressing(BUTTON_DOWN)) {
			m4_image_32(ButtonDownBitmap, ButtonDownBitmapLen/4);
			m4_flip();
		} else if(key_start_pressing(BUTTON_RIGHT)) {
			m4_image_32(ButtonRightBitmap, ButtonRightBitmapLen/4);
			m4_flip();
		} else if(key_start_pressing(BUTTON_LEFT)) {
			m4_image_32(ButtonLeftBitmap, ButtonLeftBitmapLen/4);
			m4_flip();
		} else if(key_start_pressing(BUTTON_R)) {
			m4_image_32(ButtonRBitmap, ButtonRBitmapLen/4);
			m4_flip();
		} else if(key_start_pressing(BUTTON_L)) {
			m4_image_32(ButtonLBitmap, ButtonLBitmapLen/4);
			m4_flip();
		}
	}
	
	return 0;
}
