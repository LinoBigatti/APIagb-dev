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
	m5_frame(50, 34, 60, 60, m5_RGB_color(31, 31, 31));
	
	m5_circle(80, 64, 30, m5_RGB_color(0, 31, 0));
	
	for(ii = 0; ii < 9; ii++) {
		jj_ = 3.4444444 * ii;
		jj = Round(jj_);
		m5_line(0 + 20 * ii, 0, 160 - 20 * ii, 128, m5_RGB_color(0, jj, jj));
	}
	
	m5_line(0, 64, 160, 64, m5_RGB_color(31, 0, 0));
	
	m5_flip();
	
	for(ii = 0; ii < 16; ii++) {
		jj_ = 2.06666666667 * ii;
		jj = Round(jj_);
		m5_line(0, 0 + 8 * ii, 159, 0 + 8 * ii, m5_RGB_color(jj, 0, jj));
	}
	
	for(ii = 0; ii < 16; ii++) {
		jj_ = 2.06666666667 * ii;
		jj = Round(jj_);
		m5_line(0 + 10 * ii, 0, 0 + 10 * ii, 128, m5_RGB_color(0, jj, jj));
	}
	
	m5_flip();
	
	while(1) {
		Vsync();
		
		if(++frames == 60) { //Rudimentary Vsync timer.
			frames = 0;
			m5_flip();
		}
	}
	
	return 0;
}
