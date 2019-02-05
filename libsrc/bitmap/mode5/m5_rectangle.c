//Draw a rectangle on mode 5.

#include <bitmap/mode5/m5_rectangle.h>

void m5_rectangle(u32 x, u32 y, u32 width, u32 height, m5_color clr) {
	int ii, jj;
	
	for(ii = 0; ii < height; ii++) {
		for(jj = 0; jj < width; jj++) {
			m5_pixel((jj + x), (ii + y), clr);
		}
	}
}