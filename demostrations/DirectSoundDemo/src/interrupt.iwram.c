#include "interrupt.h"

void interrupt(void) {
	u32 irqs = IO_IF & IO_IE;
	if(irqs & vblank_IRQ) {}
	if(irqs & timer1_IRQ) {
		IO_DMA1CNT = 0;
	}
	IO_IFBIOS = irqs;
	IO_IF = irqs;
}