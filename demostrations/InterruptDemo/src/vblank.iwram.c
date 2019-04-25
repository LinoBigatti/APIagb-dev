#include "vblank.h"

void vblank_interrupt(void) {
	u32 irqs = IO_IF & IO_IE;
	IO_IFBIOS = irqs;
	if(irqs & vblank_IRQ) {
		
	}
	IO_IF = irqs;
}