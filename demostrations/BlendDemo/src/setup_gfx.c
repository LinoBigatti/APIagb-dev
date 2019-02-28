#include "setup_gfx.h"

void setup_gfx(void) {
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0 | dispcnt_BG1 | dispcnt_OBJ | dispcnt_obj_mapping_1D;
	
	bg_tileset_32(tiles, tilesLen / 4, 0, 8);
	bg_palette_32(tilesPal, tilesPalLen / 4, 0);
	bg_map_32(bg1Map, bg1MapLen / 4, 30);
	bg_map_32(bg2Map, bg2MapLen / 4, 31);
	
	obj_tiles_32(sprite1Tiles, sprite1TilesLen / 4, 4, 0, 4);
	obj_tiles_32(sprite2Tiles, sprite2TilesLen / 4, 4, 16, 4);
	obj_palette_32(spritesPal, spritesPalLen / 4, 0);
	
	IO_BG0CNT = bg0cnt_prio(0) | bg0cnt_cbb(0) | bg0cnt_8bpp | bg0cnt_sbb(30) | bg0cnt_size(BG_32x32);
	IO_BG1CNT = bg1cnt_prio(1) | bg1cnt_cbb(0) | bg1cnt_8bpp | bg1cnt_sbb(31) | bg1cnt_size(BG_32x32);
	IO_BG0HOFS = IO_BG0VOFS = IO_BG1HOFS = IO_BG1VOFS = 50;
	
	obj_attributes *sprite1 = &obj_reg_memory[0];
	obj_attributes *sprite2 = &obj_reg_memory[1];
	
	sprite1->attr0 = attr0_build(attr0_Y(0), attr0_blending, attr0_normal, 0, attr0_4bpp, attr0_square);
	sprite1->attr1 = attr1_regular_build(attr1_X(170), 0, 0, attr1_size(2));
	sprite1->attr2 = attr2_build(attr2_base_tile(0), attr2_priority(0), attr2_palbank(0));
	sprite2->attr0 = attr0_build(attr0_Y(16), attr0_blending, attr0_normal, 0, attr0_4bpp, attr0_square);
	sprite2->attr1 = attr1_regular_build(attr1_X(186), 0, 0, attr1_size(2));
	sprite2->attr2 = attr2_build(attr2_base_tile(16), attr2_priority(1), attr2_palbank(0));
	
	IO_BLDCNT = bldcnt_ABG0 | bldcnt_AOBJ | bldcnt_ABG1 | bldcnt_black;
	bld_fade_from_black();
	
	IO_BLDCNT = bldcnt_ABG0 | bldcnt_AOBJ | bldcnt_normal | bldcnt_BBG1 | bldcnt_BOBJ;
	bld_set(g_alpha);
}