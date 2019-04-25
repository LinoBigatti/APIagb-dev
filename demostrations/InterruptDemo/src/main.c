#include <basics/types.h>
#include <basics/vsync.h>
#include <IO.h>
#include <bitmap/mode4.h>
#include <timer/tm2_start.h>
#include <timer/tm3_cascade.h>
#include <timer/tm2_stop.h>
#include <timer/tm3_stop.h>

#include "time.h"
#include "vblank.h"

#include "pal.h"

void draw(void) {
	for(int ii = 0; ii < 24; ii++) {
		delay(1);
		m4_line((ii * 10), 0, ((ii * 10) + 10), 160, 2);
	}
	for(int ii = 24; ii >= 0; ii--) {
		delay(1);
		m4_line(((ii * 10) + 10), 0, (ii * 10), 160, 1);
	}
	for(int ii = 0; ii < 15; ii++) {
		delay(1);
		m4_line(0, ((ii * 10) + 10), 239, ((ii * 10) + 10), 3);
	}
}

void clean(void) {
	for(int ii = 15; ii >= 0; ii--) {
		delay(1);
		m4_line(0, ((ii * 10) + 10), 239, ((ii * 10) + 10), 0);
	}
	for(int ii = 0; ii < 24; ii++) {
		delay(1);
		m4_line(((ii * 10) + 10), 0, (ii * 10), 160, 0);
	}
	for(int ii = 24; ii >= 0; ii--) {
		delay(1);
		m4_line((ii * 10), 0, ((ii * 10) + 10), 160, 0);
	}
	delay(4);
	m4_fill(0);
}

int main(void) {
	IO_ISR = vblank_interrupt;
	IO_DISPSTAT |= dispstat_vblank_IRQ;
	IO_IE = vblank_IRQ;
	IO_IME = 1;
	
	IO_DISPCNT = dispcnt_mode(4) | dispcnt_BG2;
	m4_palette_32(Pal, PalLen / 4);
	
	m4_fill(0);
	m4_frame(0, 0, 239, 159, 1);
	
	time_start();
	
	while(1) {
		draw();
		delay(5);
		clean();
		delay(5);
		m4_frame(0, 0, 239, 159, 1);
	}
	
	return 0;
}
