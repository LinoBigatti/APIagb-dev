//Draw a line in mode 5.

#include "bitmap/mode5/m5_line.h"

#include <stdlib.h>

void m5_line(u32 x1, u32 y1, u32 x2, u32 y2, m5_color clr) {
	int x, y, dx, dy, dxabs, dyabs, px, py, xend, yend, ii;
	
	if(x1 > M5_WIDTH) { //Clip x1
		x1 = M5_WIDTH;
	}
	if(x2 > M5_WIDTH) { //Clip x2
		x2 = M5_WIDTH;
	}
	
	if(y1 > M5_HEIGHT) { //Clip y1
		y1 = M5_HEIGHT;
	}
	if(y2 > M5_HEIGHT) { //Clip y2
		y2 = M5_HEIGHT;
	}
	
	dx = x2 - x1;
	dy = y2 - y1;
	dxabs = abs(dx);
	dyabs = abs(dy);
	px = 2 * dyabs - dxabs;
	py = 2 * dxabs - dyabs;
	
	if(dy == 0) { //Horizontal.
		if(dx > 0) { //Increment.
			for(ii = 0; ii < dx; ii++) {
				m5_pixel((ii + x1), y1, clr);
			}
		} else { //Decrement.
			for(ii = 0; ii > dx; ii--) {
				m5_pixel((ii + x1), y1, clr);
			}
		}
	} else if(dx == 0) { //Vertical.
		if(dy > 0) { //Increment.
			for(ii = 0; ii < dy; ii++) {
				m5_pixel(x1, (ii + y1), clr);
			}
		} else { //Decrement.
			for(ii = 0; ii > dy; ii--) {
				m5_pixel(x1, (ii + y1), clr);
			}
		}
	} else { //Diagonal.
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
			
			m5_pixel(x, y, clr); // Draw first pixel.
			
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
				
				m5_pixel(x, y, clr); //Draw current pixel.
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
			
			m5_pixel(x, y, clr); //Draw first pixel.
			
			for(ii = 0; y < yend; ii++) { //Tricky octant shit.
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
				
				m5_pixel(x, y, clr); //Draw current pixel.
			}
		}
	}
}