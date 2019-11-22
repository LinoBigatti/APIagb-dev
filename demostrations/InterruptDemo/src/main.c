#include <basics/types.h>
#include <IO.h>
#include <bitmap/mode4.h>

#include "time.h"
#include "interrupt.h"

void vBlankIntrWait()
{   asm("swi 0x05");   }

int main(void) {
	IO_ISR = interrupt;
	IO_DISPSTAT |= dispstat_hblank_IRQ | dispstat_vblank_IRQ | dispstat_vcount_IRQ | dispstat_vcount_setting(180);
	IO_IE = hblank_IRQ | vblank_IRQ | vcount_IRQ;
	IO_IME = 1;

	IO_DISPCNT = dispcnt_mode(4) | dispcnt_BG2;
	m4_fill(0);
	while(1) {
		vBlankIntrWait();
	}
}
