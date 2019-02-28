#include <basics/types.h>
#include <basics/vsync.h>
#include <IO.h>
#include <input.h>
#include <background/bg_defs.h>
#include <background/bg_tileset_32.h>
#include <background/bg_palette_32.h>
#include <background/bg_map_32.h>

#include "shared.h"
#include "marioLevel_00.h"
#include "load_next_map.h"
#include "load_last_map.h"

int main(void) {
	u32 x = 0, y = 0, curmap = 0;;
	
	bg_palette_32(sharedPal, sharedPalLen / 4, 0);
	bg_tileset_32(sharedTiles, sharedTilesLen / 4, 0, 4);
	bg_map_32(marioLevel_00Map, marioLevel_00MapLen, 30);
	
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_sbb(30) | bg0cnt_8bpp | bg0cnt_size(BG_64x32);
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
			if(y != ((256 - 160) - 16)) {
				y += 1;
			}
		}
		
		if(x == (512 - 240)) {
			if(curmap != 11) {
				load_next_map(curmap);
				curmap += 1;
				x = (256 - 240);
			}
		}
		if(x == 0) {
			if(curmap != 0) {
				load_last_map(curmap);
				curmap -= 1;
				x = 256;
			}
		}
		
		IO_BG0HOFS = x;
		IO_BG0VOFS = y;
	}
	
	return 0;
}
