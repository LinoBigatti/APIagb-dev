#include <basics/vsync.h>
#include <IO/regions.h>
#include <IO/options.h>
#include <bitmap/mode3/m3_color.h>
#include <bitmap/mode3/m3_line.h>
#include <bitmap/mode3/m3_circle.h>
#include <bitmap/mode3/m3_frame.h>
#include <bitmap/mode3/m3_rectangle.h>
#include <bitmap/mode3/m3_fill.h>

int main(void) {
	IO_DISPCNT = dispcnt_mode(3) | dispcnt_BG2;
	
	m3_fill(m3_RGB_color(12, 12, 14));
	
	m3_frame(100, 60, 40, 40, m3_RGB_color(0, 0, 0));
	m3_rectangle(101, 61, 39, 39, m3_RGB_color(31, 31, 31));
	
	m3_circle(0, 0, 30, m3_RGB_color(31, 0, 0));
	m3_circle(0, 120, 30, m3_RGB_color(31, 0, 0));
	
	m3_line(0, 0, 240, 160, m3_RGB_color(31, 0, 31));
	m3_line(240, 0, 0, 160, m3_RGB_color(31, 0, 31));
	
	m3_line(0, 80, 240, 80, m3_RGB_color(0, 31, 31));
	m3_line(120, 0, 120, 160, m3_RGB_color(0, 31, 31));
	
	while(1) {
		Vsync();
	}
	
	return 0;
}
