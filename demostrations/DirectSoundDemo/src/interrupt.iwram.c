#include "interrupt.h"

void interrupt(void) {
	u32 irqs = IO_IF & IO_IE;
	if(irqs & vblank_IRQ) {
		ds_swapBuffer();
	}
	IO_IFBIOS = irqs;
	IO_IF = irqs;
}