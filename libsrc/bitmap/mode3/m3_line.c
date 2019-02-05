//Draw a line in mode 3

#include "bitmap/mode3/m3_line.h"

#include <stdlib.h>

void m3_line(u32 x1, u32 y1, u32 x2, u32 y2, m3_color clr) {
	int x, y, dx, dy, dxabs, dyabs, px, py, xend, yend, ii;
	
	if(x1 > M3_WIDTH) { //Clip x1
		x1 = M3_WIDTH;
	}
	if(x2 > M3_WIDTH) { //Clip x2
		x2 = M3_WIDTH;
	}
	
	if(y1 > M3_HEIGHT) { //Clip y1
		y1 = M3_HEIGHT;
	}
	if(y2 > M3_HEIGHT) { //Clip y2
		y2 = M3_HEIGHT;
	}
	
	dx = x2 - x1;
	dy = y2 - y1;
	dxabs = abs(dx);
	dyabs = abs(dy);
	px = 2 * dyabs - dxabs;
	py = 2 * dxabs - dyabs;
	
	if(dyabs <= dxabs) { //X-dominant.

		//Line is drawn left to right.
		if(dx >= 0) {
			x = x1;
			y = y1;
			xend = x2;
		} else { //Line is drawn right to left.
			x = x2;
			y = y2;
			xend = x1;
		}
		
		m3_pixel(x, y, clr); // Draw first pixel.
		
		for(ii = 0; x < xend; ii++) { //Tricky octant shit.
			x += 1;
			
			if(px < 0) {
				px += 2 * dyabs;
			} else {
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
					y += 1;
				} else {
					y -= 1;
				}
				px += 2 * (dyabs - dxabs);
			}
			
			m3_pixel(x, y, clr); //Draw current pixel.
		}
	} else { //Y-dominant.
		
		if(dy >= 0) { //Line is drawn bottom to top.
			x = x1;
			y = y1;
			yend = y2;
		} else { //Line is drawn top to bottom.
			x = x2;
			y = y2;
			yend = y1;
		}
		
		m3_pixel(x, y, clr); //Draw first pixel.

		for(ii = 0; y < yend; ii++) {
			y += 1;
			
			if(py <= 0) {
				py = py + 2 * dxabs;
			} else {
				if ((dx < 0 && dy<0) || (dx > 0 && dy > 0)) {
					x += 1;
				} else {
					x -= 1;
				}
				py += 2 * (dxabs - dyabs);
			}
			
			m3_pixel(x, y, clr); //Draw current pixel.
		}
	}
}