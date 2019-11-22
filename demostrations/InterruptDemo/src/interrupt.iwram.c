#include "interrupt.h"

u16 pals[2] = {0x7C00, 0x02FF};
u32 palnumber = 0;
u32 i = 0;

void interrupt(void) {
	u32 irqs = IO_IF & IO_IE;
	if(irqs & hblank_IRQ) {
		m4_pal_memory[0] -= 1;
	}
	if(irqs & vblank_IRQ) {}
	if(irqs & vcount_IRQ) {
		if(i == 60) {
			palnumber ^= 1;
			i = 0;
		} else {
			i++;
		}
		m4_pal_memory[0] = pals[palnumber];
	}
	IO_IFBIOS = irqs;
	IO_IF = irqs;
}