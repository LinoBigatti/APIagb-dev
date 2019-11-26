#include <basics/types.h>
#include <basics/tile.h>
#include <IO.h>
#include <input.h>
#include <background/bg_defs.h>

#include "marioLevel.h"
#include "interrupt.h"
#include "music.h"

u32 song = 0;

int main(void) {
	CpuFastSet((u32*)&marioLevelTiles, (u32*)&tile_vram[0][0], 532);
	CpuFastSet((u32*)&marioLevelPal, (u32*)&bg_pal_memory[0], 128);
	CpuFastSet((u32*)&marioLevelMap, (u32*)&se_memory[30][0], 1024);

	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(30) | bg0cnt_4bpp | bg0cnt_size(BG_64x32);
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0;
	
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
			if(song != 15) { song++; } else { song = 0; }
		}
		if(key_start_pressing(BUTTON_LEFT)) {
			if(song != 0) { song--; } else { song = 15; }
		}

		if(key_start_pressing(BUTTON_A)) {
			songs[song]();
		}
	}
	return 0;
}
