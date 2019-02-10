#include <basics/types.h>
#include <basics/vsync.h>
#include <IO.h>
#include <input.h>
#include <background/bg_defs.h>
#include <background/bg_tileset_32.h>
#include <background/bg_palette_32.h>
#include <background/bg_map_32.h>

#include "marioLevel.h"

int main(void) {
	int x = 0, y = 0;
	
	bg_palette_32(marioLevelPal, marioLevelPalLen / 4, 0);
	
	bg_tileset_32(marioLevelTiles, marioLevelTilesLen / 4, 0, 4);
	
	bg_map_32(marioLevelMap, marioLevelMapLen / 4, 30);
	
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(30) | bg0cnt_4bpp | bg0cnt_size(1);
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0;
	
	while(1) {
		Vsync();
		
		key_update();
		
		if(key_is_pressed(BUTTON_RIGHT)) {
			if(x != (512 - 240)) {
				x += 1;
			}
		}
		if(key_is_pressed(BUTTON_LEFT)) {
			if(x != 0) {
				x -= 1;
			}
		}
		if(key_is_pressed(BUTTON_UP)) {
			if(y != 0) {
				y -= 1;
			}
		}
		if(key_is_pressed(BUTTON_DOWN)) {
			if(y != (256 - 160)) {
				y += 1;
			}
		}
		
		IO_BG0HOFS = x;
		IO_BG0VOFS = y;
	}
	
	return 0;
}
