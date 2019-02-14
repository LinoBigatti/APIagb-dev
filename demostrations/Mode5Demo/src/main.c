#include <basics/vsync.h>
#include <basics/round.h>
#include <IO/regions.h>
#include <IO/options.h>
#include <bitmap/mode5/m5_color.h>
#include <bitmap/mode5/m5_line.h>
#include <bitmap/mode5/m5_circle.h>
#include <bitmap/mode5/m5_frame.h>
#include <bitmap/mode5/m5_rectangle.h>
#include <bitmap/mode5/m5_fill.h>
#include <bitmap/mode5/m5_flip.h>

int main(void) {
	m5_flip();
	
	IO_DISPCNT = dispcnt_mode(5) | dispcnt_BG2;
	
	int ii;
	float jj_;
	int jj;
	int frames = 0;
	
	m5_fill(m5_RGB_color(10, 10, 10));
	
	m5_rectangle(51, 35, 59, 59, m5_RGB_color(0, 0, 31));
	
	
	while(1) {
		Vsync();
		
		if(++frames == 60) { //Rudimentary Vsync timer.
			frames = 0;
			m5_flip();
		}
	}
	
	return 0;
}
