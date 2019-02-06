#include <basics/types.h>
#include <basics/vsync.h>
#include <IO.h>
#include <bitmap/mode4.h>

#include "pal.h"

int main(void) {
	int frames = 0;
	
	m4_flip();
	
	IO_DISPCNT = dispcnt_mode(4) | dispcnt_BG2;
	
	m4_palette_32(Pal, PalLen / 4);
	
	m4_fill(7);
	
	m4_line(0, 80, 120, 0, 1);
	m4_line(240, 80, 120, 0, 1);
	
	m4_circle(120, 80, 40, 2);
	
	m4_frame(0, 80, 239, 79, 0);
	m4_rectangle(1, 81, 237, 78, 3);
	
	m4_flip();
	
	m4_fill(0);
	
	m4_line(0, 80, 120, 0, 3);
	m4_line(240, 80, 120, 0, 3);
	
	m4_circle(120, 80, 40, 4);
	
	m4_frame(0, 80, 239, 79, 7);
	m4_rectangle(1, 81, 237, 78, 1);
	
	while(1) {
		Vsync();
		
		if(++frames == 60) { //Rudimentary Vsync timer.
			frames = 0;
			m4_flip();
		}
	}
	
	return 0;
}