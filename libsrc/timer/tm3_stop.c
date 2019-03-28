//Stop the timer 3.


#include <timer/tm3_stop.h>

void tm3_stop(void) {
	IO_TM3CNT = 0;
}
