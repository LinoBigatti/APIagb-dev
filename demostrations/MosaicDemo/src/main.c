#include <basics/types.h>
#include <basics/vsync.h>
#include <IO.h>
#include <input.h>
#include <object.h>
#include <background.h>

#include "bg.h"
#include "metroid.h"

int main(void) {
	u32 x = 0, y = 0, omh = 0, omv = 0, bmh = 0, bmv = 0;
	
	obj_clear_all();
	
	obj_tiles_32(metroidTiles, metroidTilesLen / 4, 4, 0, 8);
	obj_palette_32(metroidPal, 0);
	
	bg_tileset_32(bgTiles, bgTilesLen / 4, 0, 8);
	bg_palette_32(bgPal, bgPalLen / 4, 0);
	bg_map_32(bgMap, bgMapLen / 4, 31);
	
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0 | dispcnt_OBJ | dispcnt_obj_mapping_1D;
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(31) | bg0cnt_8bpp | bg0cnt_size(0) | bg0cnt_mosaic;
	IO_MOSAIC = bg_mosaic(bmh, bmv) | obj_mosaic(omh, omv);
	
	obj_attributes *metroid = &obj_reg_memory[0];
	
	metroid->attr0 = attr0_build(attr0_Y(0), attr0_regular, attr0_normal, attr0_mosaic, attr0_8bpp, attr0_square);
	metroid->attr1 = attr1_regular_build(attr1_X(0), 0, 0, attr1_size(3));
	metroid->attr2 = attr2_build(attr2_base_tile(0), attr2_priority(0), attr2_palbank(0));
	
	while(1) {
		Vsync();
		key_update();
		
		if(key_is_pressed(BUTTON_RIGHT)) {
			if((x + 13) < 240) {
				x += 1;
			}
		}
		if(key_is_pressed(BUTTON_LEFT)) {
			if(x > 0) {
				x -= 1;
			}
		}
		if(key_is_pressed(BUTTON_DOWN)) {
			if((y + 16) < 160) {
				y += 1;
			}
		}
		if(key_is_pressed(BUTTON_UP)) {
			if(y > 0) {
				y -= 1;
			}
		}
		
		if(key_is_pressed(BUTTON_L) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			omh -= 1;
		}
		if(key_is_pressed(BUTTON_R) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			omh += 1;
		}
		if(key_is_pressed(BUTTON_L) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			omv -= 1;
		}
		if(key_is_pressed(BUTTON_R) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			omv += 1;
		}
		if(key_start_pressing(BUTTON_A)) {
			omh = 0;
			omv = 0;
		}
		
		if(key_is_pressed(BUTTON_L) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			bmh -= 1;
		}
		if(key_is_pressed(BUTTON_R) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			bmh += 1;
		}
		if(key_is_pressed(BUTTON_L) && key_is_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			bmv -= 1;
		}
		if(key_is_pressed(BUTTON_R) && key_is_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			bmv += 1;
		}
		if(key_start_pressing(BUTTON_B)) {
			bmh = 0;
			bmv = 0;
		}
		
		IO_MOSAIC = bg_mosaic(bmh >> 2, bmv >> 2) | obj_mosaic(omh >> 2, omv >> 2);
		metroid->attr0 = attr0_build(attr0_Y(y), attr0_regular, attr0_normal, attr0_mosaic, attr0_8bpp, attr0_square);
		metroid->attr1 = attr1_regular_build(attr1_X(x), 0, 0, attr1_size(3));
		metroid->attr2 = attr2_build(attr2_base_tile(0), attr2_priority(0), attr2_palbank(0));
	}
	
	return 0;
}
