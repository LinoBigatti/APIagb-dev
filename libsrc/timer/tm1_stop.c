//Stop the timer 1.


#include <timer/tm1_stop.h>

void tm1_stop(void) {
	IO_TM1CNT = 0;
}
