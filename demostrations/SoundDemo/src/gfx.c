//Load graphics.

#include "gfx.h"

int sbb = 0;

void loadGFX(void) {
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(24 + sbb) | bg0cnt_8bpp | bg0cnt_size(BG_32x32);
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0;

	CpuFastSet((u32*)&songSharedPal, (u32*)&bg_pal_memory[0], songSharedPalLen / 4);
	LZ77UnCompVRAM((u32*)&songSharedTiles, (u32*)&tile_vram[0][0]);

	LZ77UnCompVRAM((u32*)&song1Map, (u32*)&se_memory[24][0]);
	LZ77UnCompVRAM((u32*)&song2Map, (u32*)&se_memory[25][0]);
	LZ77UnCompVRAM((u32*)&song3Map, (u32*)&se_memory[26][0]);
	LZ77UnCompVRAM((u32*)&song4Map, (u32*)&se_memory[27][0]);
	LZ77UnCompVRAM((u32*)&song5Map, (u32*)&se_memory[28][0]);
	LZ77UnCompVRAM((u32*)&song6Map, (u32*)&se_memory[29][0]);
	LZ77UnCompVRAM((u32*)&song7Map, (u32*)&se_memory[30][0]);
	LZ77UnCompVRAM((u32*)&song8Map, (u32*)&se_memory[31][0]);
}

void nextScreen(void) {
	sbb++;
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(24 + sbb) | bg0cnt_8bpp | bg0cnt_size(BG_32x32);
}

void prevScreen(void) {
	sbb--;
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(24 + sbb) | bg0cnt_8bpp | bg0cnt_size(BG_32x32);
}

void setScreen(int sbb_) {
	sbb = sbb_;
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(24 + sbb) | bg0cnt_8bpp | bg0cnt_size(BG_32x32);
}