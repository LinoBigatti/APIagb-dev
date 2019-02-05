//Draw a rectangle on mode 3.

#include <bitmap/mode3/m3_rectangle.h>

void m3_rectangle(u32 x, u32 y, u32 width, u32 height, m3_color clr) {
	int ii, jj;
	
	for(ii = 0; ii < height; ii++) {
		for(jj = 0; jj < width; jj++) {
			m3_pixel((jj + x), (ii + y), clr);
		}
	}
}