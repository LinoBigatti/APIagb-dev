#include <basics/types.h>
#include <IO.h>
#include <input.h>

#include "marioLevel.h"
#include "interrupt.h"
#include "music.h"
#include "gfx.h"

u32 song = 0;

int main(void) {
	loadGFX();

	IO_SNDSTAT = sndstat_enable;

	IO_SNDDMGCNT = snddmgcnt_lvol(100) | snddmgcnt_rvol(100) | snddmgcnt_lsqr1 | snddmgcnt_rsqr1;

	IO_SNDDSCNT = snddscnt_DMG100;

	IO_SND1CNT = snd1cnt_duty1_2 | snd1cnt_time(7) | snd1cnt_dec | snd1cnt_initial(15);

	IO_ISR = interrupt;
	IO_DISPSTAT |= dispstat_vblank_IRQ;
	IO_IE = vblank_IRQ;
	IO_IME = 1;

	while(1) {
		VBlankIntrWait();

		if(key_start_pressing(BUTTON_R)) {
			if(octave != 7) { octave++; }
		}
		if(key_start_pressing(BUTTON_L)) {
			if(octave != 0) { octave--; }
		}

		if(key_start_pressing(BUTTON_RIGHT)) {
			if(song != 7) { song++; nextScreen(); } else { song = 0; setScreen(0); }
		}
		if(key_start_pressing(BUTTON_LEFT)) {
			if(song != 0) { song--; prevScreen(); } else { song = 7; setScreen(7); }
		}

		if(key_start_pressing(BUTTON_A)) {
			songs[song]();
		}
	}
	return 0;
}
