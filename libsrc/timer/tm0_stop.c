//Stop the timer 0.


#include <timer/tm0_stop.h>

void tm0_stop(void) {
	IO_TM0CNT = 0;
}
