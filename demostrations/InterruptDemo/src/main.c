#include <basics/types.h>
#include <basics/bios.h>
#include <IO.h>
#include <background/bg_tileset_32.h>
#include <background/bg_palette_32.h>
#include <background/bg_map_32.h>
#include <input.h>
#include <object.h>

#include "interrupt.h"

#include "bowser.h"
#include "bg.h"

void initGraphics(void) {
	obj_clear_all();
	
	LZ77UnCompVRAM(&bowserTiles, (u16*)&tile8_vram[4][0]);
	CpuSet(&bowserPal, &obj_pal_memory[0], 256);
	
	CpuFastSet((u32*)&bgTiles, (u32*)&tile_vram[0][0], 16);
	CpuFastSet((u32*)&bgPal, (u32*)&bg_pal_memory[0], 8);
	CpuFastSet((u32*)&bgMap, (u32*)&se_memory[31][0], 512);
	
	IO_DISPCNT = dispcnt_OBJ | dispcnt_obj_mapping_1D | dispcnt_mode(0) | dispcnt_BG0;
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(31) | bg0cnt_4bpp | bg0cnt_size(BG_64x32);
}

int main(void) {
	initGraphics();

	obj_attributes *bowser = &obj_reg_memory[0];
	obj_affine_src bowserAff = {0x0100, 0x0100, 0};
	obj_affine bowserAffParams;

	ObjAffineSet(&bowserAff, &bowserAffParams.pa, 1, 8);
	
	u32 x = 0, y = 0, doubleFlag = attr0_normal;
	
	bowser->attr0 = attr0_build(attr0_Y(y), attr0_affine, doubleFlag, 0, attr0_8bpp, attr0_square);
	bowser->attr1 = attr1_affine_build(attr1_X(x), attr1_aff_index(0), attr1_size(OBJ_64x64));
	bowser->attr2 = attr2_build(attr2_base_tile(0), attr2_priority(0), attr2_palbank(0));

	IO_ISR = interrupt;
	IO_DISPSTAT |= dispstat_vblank_IRQ;
	IO_IE = vblank_IRQ;
	IO_IME = 1;

	while(1) {
		VBlankIntrWait();

		if(key_is_pressed(BUTTON_RIGHT) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			if((x + 60) < 240) {
				x += 1;
			}
		}
		if(key_is_pressed(BUTTON_LEFT) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			if((x + 3) > 0) {
				x -= 1;
			}
		}
		if(key_is_pressed(BUTTON_DOWN) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			if((y + 60) < 160) {
				y += 1;
			}
		}
		if(key_is_pressed(BUTTON_UP) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			if((y + 3) > 0) {
				y -= 1;
			}
		}
		
		if(key_is_pressed(BUTTON_R) && key_is_not_pressed(BUTTON_START)) {
			bowserAff.alpha -= 0x0111;
		}
		if(key_is_pressed(BUTTON_L) && key_is_not_pressed(BUTTON_START)) {
			bowserAff.alpha += 0x0111;
		}

		if(key_is_pressed(BUTTON_R) && key_is_pressed(BUTTON_START)) {
			bowserAff.alpha -= Sqrt(bowserAff.alpha);
		}
		if(key_is_pressed(BUTTON_L) && key_is_pressed(BUTTON_START)) {
			bowserAff.alpha += Sqrt(bowserAff.alpha);
		}
		
		if(key_start_pressing(BUTTON_DOWN) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			bowserAff.sy *= 2;
		}
		if(key_start_pressing(BUTTON_UP) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			bowserAff.sy = Div(bowserAff.sy, 2);
		}
		if(key_start_pressing(BUTTON_LEFT) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			bowserAff.sx *= 2;
		}
		if(key_start_pressing(BUTTON_RIGHT) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			bowserAff.sx = Div(bowserAff.sx, 2);
		}

		if(key_start_pressing(BUTTON_A)) {
			if(doubleFlag == attr0_normal) {
				doubleFlag = attr0_affine_double;
				x -= 32;
				y -= 32;
			} else {
				doubleFlag = attr0_normal;
				x += 32;
				y += 32;
			}
		}
		if(key_start_pressing(BUTTON_B)) {
			bowserAff.alpha = 0;
			bowserAff.sx = 0x0100;
			bowserAff.sy = 0x0100;
		}
		
		bowser->attr0 = attr0_build(attr0_Y(y), attr0_affine, doubleFlag, 0, attr0_8bpp, attr0_square);
		bowser->attr1 = attr1_affine_build(attr1_X(x), attr1_aff_index(0), attr1_size(3));
		bowser->attr2 = attr2_build(attr2_base_tile(0), attr2_priority(0), attr2_palbank(0));
		ObjAffineSet(&bowserAff, &bowserAffParams.pa, 1, 8);
		obj_aff_memory->pa = bowserAffParams.pa;
		obj_aff_memory->pb = bowserAffParams.pb;
		obj_aff_memory->pc = bowserAffParams.pc;
		obj_aff_memory->pd = bowserAffParams.pd;
	}
	
	return 0;
}
