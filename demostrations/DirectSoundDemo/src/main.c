#include <basics/types.h>
#include <basics/bios.h>
#include <IO.h>
#include <DMA.h>
#include <timers.h>

#include <sound/ds_initbuffer.h>
#include <sound/ds_mainmixer.h>
#include <sound/snd_defs.h>

#include "interrupt.h"

#include "pianoC5.h"
#include "pianoG5.h"
#include "tom.h"

s8 buffer[FREQ43959_SIZE * 2];

soundChannel channels[4] = {
	{
		.data = (s8*)&tom, .pos = 0, .inc = 4109, /*(44100 << 12) / 43959 (rounded)*/ .vol = 64, .length = 17732 << 12, .loop = 17732 << 12
	},
	{
		.data = (s8*)&pianoC5, .pos = 0, .inc = 4109, /*(44100 << 12) / 43959 (rounded)*/ .vol = 64, .length = 41816 << 12, .loop = 41816 << 12
	},
	{
		.data = (s8*)&pianoG5, .pos = 0, .inc = 4109, /*(44100 << 12) / 43959 (rounded)*/ .vol = 64, .length = 88951 << 12, .loop = 88951 << 12
	},
	{
		.data = NULL, .pos = 0, .inc = 0, .vol = 0, .length = 0, .loop = NULL
	}
};

int main(void) {
	IO_ISR = interrupt;
	IO_DISPSTAT |= dispstat_vblank_IRQ;
	IO_IE = vblank_IRQ;
	IO_IME = 1;

	ds_initBuffer(buffer, FREQ43959_SIZE);

	IO_SNDSTAT = sndstat_enable;
	IO_SNDDMGCNT = snddmgcnt_lvol(100) | snddmgcnt_lvol(100) | snddmgcnt_lwave | snddmgcnt_rwave;
	IO_SNDDSCNT = snddscnt_DMG100 | snddscnt_A100 | snddscnt_AL | snddscnt_AR | snddscnt_Areset | snddscnt_ATMR0;
	IO_SND3SEL = snd3sel_enable;
	tm0_start(FREQ43959_TIMER, 0, 0);
	dma1_32((u32*)mainBuffer.bufferStart, (u32*)&IO_FIFOA, 0, dmacnt_fixeddst, dmacnt_incsrc, dmacnt_fifo, dmacnt_repeat);

	while(1) {
		VBlankIntrWait();
		ds_mainMixer((soundChannel*)&channels, 4);
	}
}
