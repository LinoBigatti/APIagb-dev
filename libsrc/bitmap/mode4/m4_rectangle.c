//Draw a rectangle on mode 4.

#include <bitmap/mode4/m4_rectangle.h>

void m4_rectangle(u32 x, u32 y, u32 width, u32 height, m4_color_entry clr) {
	int ii, jj;
	
	for(ii = 0; ii < height; ii++) {
		m4_line(x, (ii + y), (x + width), (ii + y), clr);
	}
}