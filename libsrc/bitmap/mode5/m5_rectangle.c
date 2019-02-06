//Draw a rectangle on mode 5.

#include <bitmap/mode5/m5_rectangle.h>

void m5_rectangle(u32 x, u32 y, u32 width, u32 height, m5_color clr) {
	int ii;
	
	for(ii = 0; ii < height; ii++) {
		m5_line(x, (ii + y), (x + width), (ii + y), clr);
	}
}