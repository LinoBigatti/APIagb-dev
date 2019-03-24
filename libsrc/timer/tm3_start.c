//Start the timer 3.


#include <timer/tm3_start.h>

void tm3_start(u16 start, u16 freq, u16 other) {
	IO_TM3DATA = tm3data_start(start);
	IO_TM3CNT = tmcnt_enable | freq | other;
}
