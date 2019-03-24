//Start the timer 0.


#include <timer/tm0_start.h>

void tm0_start(u16 start, u16 freq, u16 other) {
	IO_TM0DATA = tm0data_start(start);
	IO_TM0CNT = tmcnt_enable | freq | other;
}
