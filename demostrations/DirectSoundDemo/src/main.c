#include <basics/types.h>
#include <basics/bios.h>
#include <IO.h>
#include <DMA.h>
#include <timers.h>

#include "interrupt.h"

#include "pianoC5.h"

int main(void) {
	IO_ISR = interrupt;
	IO_DISPSTAT |= dispstat_vblank_IRQ;
	IO_IE = vblank_IRQ | timer1_IRQ;
	IO_IME = 1;

	IO_SNDSTAT = sndstat_enable;
	IO_SNDDMGCNT = snddmgcnt_lvol(100) | snddmgcnt_lvol(100) | snddmgcnt_lwave | snddmgcnt_rwave;
	IO_SNDDSCNT = snddscnt_DMG100 | snddscnt_A100 | snddscnt_AL | snddscnt_AR | snddscnt_Areset | snddscnt_ATMR0;
	IO_SND3SEL = snd3sel_enable;
	tm0_start(65536 - (16777216 / 44100), 0, 0);
	tm1_cascade(0, tmcnt_IRQ);
	dma1_32((u32*)pianoC5, (u32*)&IO_FIFOA, 0, dmacnt_fixeddst, dmacnt_incsrc, dmacnt_fifo, dmacnt_repeat);

	while(1) {
		VBlankIntrWait();
	}
}
