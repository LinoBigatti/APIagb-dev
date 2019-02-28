#include "load_controls.h"

void load_controls(void) {
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0;
	
	IO_BLDCNT = bldcnt_ABG0 | bldcnt_black;
	bldy_set(0);
	
	bld_fade_to_black();
	
	bg_tileset_32(controlsTiles, controlsTilesLen / 4, 0, 8);
	bg_palette_32(controlsPal, controlsPalLen / 4, 0);
	bg_map_32(controlsMap, controlsMapLen / 4, 31);
	
	IO_BG0CNT = bg0cnt_prio(0) | bg0cnt_cbb(0) | bg0cnt_8bpp | bg0cnt_sbb(31) | bg0cnt_size(BG_32x32);
	
	bld_fade_from_black();
	
	while(key_is_not_pressed(BUTTON_A)) {
		Vsync();
		key_update();
	}
	
	bld_fade_to_black();
}