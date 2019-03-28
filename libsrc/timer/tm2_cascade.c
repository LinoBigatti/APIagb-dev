//Start the timer 2 as cascade.


#include <timer/tm2_cascade.h>

void tm2_cascade(u16 start, u16 other) {
	IO_TM2DATA = tm2data_start(start);
	IO_TM2CNT = tmcnt_enable | tmcnt_cascade | other;
}
