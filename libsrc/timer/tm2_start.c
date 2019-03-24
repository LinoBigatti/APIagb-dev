//Start the timer 2.


#include <timer/tm2_start.h>

void tm2_start(u16 start, u16 freq, u16 other) {
	IO_TM2DATA = tm2data_start(start);
	IO_TM2CNT = tmcnt_enable | freq | other;
}
