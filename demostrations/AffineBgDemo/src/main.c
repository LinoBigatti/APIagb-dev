#include <basics/types.h>
#include <basics/vsync.h>
#include <IO.h>
#include <input.h>
#include <background.h>

#include "bg.h"

int main(void) {
	int x = 0, y = 0, sx = 256, sy = 256, hx = 0, hy = 0, angle = 0;
	
	bg_palette_32(bgPal, bgPalLen / 4, 0);
	
	bg_tileset_32(bgTiles, bgTilesLen / 4, 0, 8);
	
	bg_map_32(bgMap, bgMapLen / 4, 28);
	
	IO_BG2CNT = bg2cnt_cbb(0) | bg2cnt_sbb(28) | bg2cnt_8bpp | bg2cnt_size(1);
	IO_DISPCNT = dispcnt_mode(2) | dispcnt_BG2;
	
	bg_affine *bgAff = &bg_aff_memory[2];
	
	bg_aff_identity(bgAff);
	
	while(1) {
		Vsync();
		
		key_update();
		
		if(key_is_pressed(BUTTON_RIGHT) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			x += 2;
		}
		if(key_is_pressed(BUTTON_LEFT) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			x -= 2;
		}
		if(key_is_pressed(BUTTON_DOWN) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			y += 2;
		}
		if(key_is_pressed(BUTTON_UP) && key_is_not_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			y -= 2;
		}
		
		if(key_is_pressed(BUTTON_RIGHT) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			sx -= 5;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_LEFT) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			sx += 5;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_DOWN) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			sy += 5;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_UP) && key_is_pressed(BUTTON_SELECT) && key_is_not_pressed(BUTTON_START)) {
			sy -= 5;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		
		if(key_is_pressed(BUTTON_RIGHT) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			hx += 5;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_LEFT) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			hx -= 5;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_DOWN) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			hy -= 5;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_UP) && key_is_not_pressed(BUTTON_SELECT) && key_is_pressed(BUTTON_START)) {
			hy += 5;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		
		if(key_is_pressed(BUTTON_R)) {
			angle -= 100;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		if(key_is_pressed(BUTTON_L)) {
			angle += 100;
			bg_aff_rotate_scale_and_shear(bgAff, sx, sy, hx, hy, angle);
		}
		
		if(key_start_pressing(BUTTON_A)) {
			IO_BG2CNT ^= bg2cnt_wraparound;
		}
		if(key_start_pressing(BUTTON_B)) {
			bg_aff_identity(bgAff);
			angle = 0;
			sx = 256;
			sy = 256;
			hx = 0;
			hy = 0;
		}
		
		bg_aff_move(bgAff, x, y);
	}
	
	return 0;
}
