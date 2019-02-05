//Draw a frame on mode 5.

#include <bitmap/mode5/m5_frame.h>

void m5_frame(u32 x, u32 y, u32 width, u32 height, m5_color clr) {
	int x0 = x;
	int y0 = y;
	int x1 = x;
	int y1 = y + height;
	int x2 = x + width;
	int y2 = y + height;
	int x3 = x + width;
	int y3 = y;
	
	m5_line(x0, y0, x1, y1, clr);
	m5_line(x1, y1, x2, y2, clr);
	m5_line(x2, y2, x3, y3, clr);
	m5_line(x3, y3, x0, y0, clr);
}