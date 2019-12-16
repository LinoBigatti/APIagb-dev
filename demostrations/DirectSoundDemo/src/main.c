#include <basics/types.h>
#include <basics/bios.h>
#include <IO.h>
#include <DMA.h>
#include <timers.h>

#include <sound/ds_initbuffer.h>
#include <sound/snd_defs.h>

#include "interrupt.h"

#include "pianoC5.h"

s8 buffer[FREQ43959_SIZE * 2];

volatile soundChannel channelA = {
	.data = (s8*)&pianoC5, .pos = 0, .inc = 4109, /*(44100 << 12) / 43959 (rounded)*/ .vol = 64, .length = 41816 << 12, .loop = NULL
};

void ds_mainMixer(void) {
	if(channelA.data != NULL) {
		for(int i = 0; i < mainBuffer.size; i++) {
			mainBuffer.freeBuffer[i] = channelA.data[channelA.pos >> 12] * channelA.vol >> 6;
			channelA.pos += channelA.inc;

			if(channelA.pos >= channelA.length) {
				if(channelA.loop != NULL) {
					while(channelA.pos >= channelA.length) {
						channelA.pos -= channelA.loop;
					}
				} else {
					channelA.data = NULL;
				}
			}
		}
	} else {
		for(int i = 0; i < mainBuffer.size; i++) { mainBuffer.freeBuffer[i] = 0; }
	}
}

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
		ds_mainMixer();
	}
}
