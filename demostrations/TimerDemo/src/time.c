#include "time.h"

void time_start(void) {
	tm3_cascade(0x0000, 0);
	tm2_start(-0x2000, tmcnt_freq_1024, 0);
}

void delay(int s) {
	int seconds = tm3data_read();
	for(int ii = 0; ii < s; ii++) {
		while(seconds == tm3data_read()) {
			Vsync();
		}
	}
}
