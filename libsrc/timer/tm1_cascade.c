//Start the timer 1 as cascade.


#include <timer/tm1_cascade.h>

void tm1_cascade(u16 start, u16 other) {
	IO_TM1DATA = tm1data_start(start);
	IO_TM1CNT = tmcnt_enable | tmcnt_cascade | other;
}
