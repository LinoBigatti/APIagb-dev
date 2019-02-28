#include "load_title.h"

void load_title(void) {
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0;
	
	IO_BLDCNT = bldcnt_ABG0 | bldcnt_white;
	bldy_set(1);
	
	bg_tileset_32(titleTiles, titleTilesLen / 4, 0, 8);
	bg_palette_32(titlePal, titlePalLen / 4, 0);
	bg_map_32(titleMap, titleMapLen / 4, 31);
	
	IO_BG0CNT = bg0cnt_prio(0) | bg0cnt_cbb(0) | bg0cnt_8bpp | bg0cnt_sbb(31) | bg0cnt_size(BG_32x32);
	
	bld_fade_from_white();
	
	float a = 0, s;
	int ii = 0, ss;
	while(key_is_not_pressed(BUTTON_START)) {
		Vsync();
		key_update();
		
		if(ii == 0) {
			s = 0.01;
			ss = 1;
		} else if(ii == 30) {
			s = -0.01;
			ss = -1;
		}
		
		ii += ss;
		a += s;
		bldy_set(a);
	}
}