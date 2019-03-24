//Start the timer 3 as cascade.


#include <timer/tm3_cascade.h>

void tm3_start(u16 start, u16 other) {
	IO_TM3DATA = tm3data_start(start);
	IO_TM3CNT = tmcnt_enable | tmcnt_cascade | other;
}
