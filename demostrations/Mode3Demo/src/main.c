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
	int ii, jj;
	
	IO_DISPCNT = dispcnt_mode(3) | dispcnt_BG2;
	
	m3_fill(m3_RGB_color(12, 12, 14));
	
	m3_frame(0, 0, 240, 160, m3_RGB_color(0, 0, 0));
	
	m3_circle(70, 45, 30, m3_RGB_color(31, 31, 0));
	
	m3_frame(132, 8, 95, 63, m3_RGB_color(0, 31, 31));
	
	m3_rectangle(10, 90, 110, 60, m3_RGB_color(31, 0, 31));
	
	m3_circle(190, 120, 30, m3_RGB_color(0, 0, 0));
	for(ii = 29; ii > 0; ii--) {
		m3_circle(190, 120, ii, m3_RGB_color(31, 31, 31));
	}
	
    for(ii = 0; ii <= 8; ii++)
    {
        jj = 3 * ii + 7;
        m3_line(132 + 11 * ii, 9, 226, 12 + 7 * ii, m3_RGB_color(jj, 0, jj));
        m3_line(226 - 11 * ii, 70, 133, 69 - 7 * ii, m3_RGB_color(jj, 0, jj));
    }
	
	while(1) {
		Vsync();
	}
	
	return 0;
}
