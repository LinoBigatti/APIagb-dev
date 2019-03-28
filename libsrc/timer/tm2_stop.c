//Stop the timer 2.


#include <timer/tm2_stop.h>

void tm2_stop(void) {
	IO_TM2CNT = 0;
}
