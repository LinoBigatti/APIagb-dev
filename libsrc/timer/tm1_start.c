//Start the timer 1.


#include <timer/tm1_start.h>

void tm1_start(u16 start, u16 freq, u16 other) {
	IO_TM1DATA = tm1data_start(start);
	IO_TM1CNT = tmcnt_enable | freq | other;
}
