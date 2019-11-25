#include <basics/types.h>
#include <basics/bios.h>
#include <basics/tile.h>
#include <IO.h>
#include <input.h>
#include <background/bg_defs.h>
#include <sound/get_note_rate.h>

#include "marioLevel.h"
#include "interrupt.h"

void delay(u32 cycles) {
	for(int i = 0; i < cycles; i++) {
		VBlankIntrWait();
	}
}

#define playNote(note, octave) IO_SND1FREQ = snd1freq_rate(get_note_rate(note, octave)) | snd1freq_reset

void musicalScale(u32 octave) {
	playNote(NOTE_C, octave);
	delay(30);
	playNote(NOTE_D, octave);
	delay(30);
	playNote(NOTE_E, octave);
	delay(30);
	playNote(NOTE_F, octave);
	delay(30);
	playNote(NOTE_G, octave);
	delay(30);
	playNote(NOTE_A, octave);
	delay(30);
	playNote(NOTE_B, octave);
	delay(30);
	playNote(NOTE_C, octave + 1);
	delay(30);
}

void happyBirthday(void) {
	playNote(NOTE_C, 0);
	delay(15);
	playNote(NOTE_C, 0);
	delay(15);
	playNote(NOTE_D, 0);
	delay(30);
	playNote(NOTE_C, 0);
	delay(30);
	playNote(NOTE_F, 0);
	delay(30);
	playNote(NOTE_E, 0);
	delay(60);

	playNote(NOTE_C, 0);
	delay(15);
	playNote(NOTE_C, 0);
	delay(15);
	playNote(NOTE_D, 0);
	delay(30);
	playNote(NOTE_C, 0);
	delay(30);
	playNote(NOTE_G, 0);
	delay(30);
	playNote(NOTE_F, 0);
	delay(60);

	playNote(NOTE_C, 0);
	delay(15);
	playNote(NOTE_C, 0);
	delay(15);
	playNote(NOTE_C, 1);
	delay(30);
	playNote(NOTE_A, 0);
	delay(30);
	playNote(NOTE_F, 0);
	delay(15);
	playNote(NOTE_F, 0);
	delay(15);
	playNote(NOTE_E, 0);
	delay(30);
	playNote(NOTE_D, 0);
	delay(30);

	playNote(NOTE_BES, 0);
	delay(15);
	playNote(NOTE_BES, 0);
	delay(15);
	playNote(NOTE_A, 0);
	delay(30);
	playNote(NOTE_F, 0);
	delay(30);
	playNote(NOTE_G, 0);
	delay(30);
	playNote(NOTE_F, 0);
	delay(60);
}

int octave = 0;

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
			octave++;
		}
		if(key_start_pressing(BUTTON_L)) {
			octave--;
		}

		if(key_start_pressing(BUTTON_A)) {
			happyBirthday();
		}
	}
	return 0;
}
