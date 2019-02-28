#include <basics/types.h>
#include <basics/vsync.h>
#include <IO.h>
#include <background/bg_tileset_32.h>
#include <background/bg_palette_32.h>
#include <background/bg_map_32.h>
#include <input.h>
#include <object.h>

#include "bowser.h"
#include "bg.h"

int main(void) {
	obj_clear_all();
	
	obj_tiles_32(bowserTiles, bowserTilesLen / 4, 4, 0, 8);
	obj_palette_32(bowserPal, bowserPalLen / 4, 0);
	
	bg_tileset_32(bgTiles, bgTilesLen / 4, 0, 4);
	bg_palette_32(bgPal, bgPalLen / 4, 0);
	bg_map_32(bgMap, bgMapLen / 4, 31);
	
	IO_DISPCNT = dispcnt_OBJ | dispcnt_obj_mapping_1D | dispcnt_mode(0) | dispcnt_BG0;
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(31) | bg0cnt_4bpp | bg0cnt_size(BG_64x32);
	
	obj_attributes *bowser = &obj_reg_memory[0];
	obj_affine *bowserAff = &obj_aff_memory[0];
	
	u32 x = 0, y = 0, angle = 0, sx = 256, sy = 256, doubleFlag = attr0_normal, hx = 0, hy = 0;
	
	bowser->attr0 = attr0_build(attr0_Y(y), attr0_affine, doubleFlag, 0, attr0_8bpp, attr0_square);
	bowser->attr1 = attr1_affine_build(attr1_X(x), attr1_aff_index(0), attr1_size(3));
	bowser->attr2 = attr2_build(attr2_base_tile(0), attr2_priority(0), attr2_palbank(0));
	
	obj_aff_identity(bowserAff);
	
	while(1) {
		Vsync();
		
		key_update();
		
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
		
		if(key_is_pressed(BUTTON_RIGHT) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			sx -= 5;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_LEFT) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			sx += 5;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_DOWN) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			sy += 5;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_UP) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			sy -= 5;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
		}
		
		if(key_is_pressed(BUTTON_RIGHT) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			hx += 5;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_LEFT) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			hx -= 5;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_DOWN) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			hy -= 5;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_UP) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			hy += 5;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
		}
		
		if(key_is_pressed(BUTTON_R)) {
			angle -= 100;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_L)) {
			angle += 100;
			obj_aff_rotate_scale_and_shear(bowserAff, sx, sy, hx, hy, angle);
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
			obj_aff_identity(bowserAff);
			angle = 0;
			sx = 256;
			sy = 256;
			hx = 0;
			hy = 0;
		}
		
		bowser->attr0 = attr0_build(attr0_Y(y), attr0_affine, doubleFlag, 0, attr0_8bpp, attr0_square);
		bowser->attr1 = attr1_affine_build(attr1_X(x), attr1_aff_index(0), attr1_size(3));
		bowser->attr2 = attr2_build(attr2_base_tile(0), attr2_priority(0), attr2_palbank(0));
		
	}
	
	return 0;
}
