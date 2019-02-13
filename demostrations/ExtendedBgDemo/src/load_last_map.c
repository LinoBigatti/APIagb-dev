//Load the last map.

#include "load_last_map.h"

void load_last_map(u32 curmap) {
	u32 map = curmap - 1;
	
	switch(map) {
		case 0:
			bg_map_32(marioLevel_00Map, marioLevel_00MapLen, 30);
			break;
		case 1:
			bg_map_32(marioLevel_01Map, marioLevel_01MapLen, 30);
			break;
		case 2:
			bg_map_32(marioLevel_02Map, marioLevel_02MapLen, 30);
			break;
		case 3:
			bg_map_32(marioLevel_03Map, marioLevel_03MapLen, 30);
			break;
		case 4:
			bg_map_32(marioLevel_04Map, marioLevel_04MapLen, 30);
			break;
		case 5:
			bg_map_32(marioLevel_05Map, marioLevel_05MapLen, 30);
			break;
		case 6:
			bg_map_32(marioLevel_06Map, marioLevel_06MapLen, 30);
			break;
		case 7:
			bg_map_32(marioLevel_07Map, marioLevel_07MapLen, 30);
			break;
		case 8:
			bg_map_32(marioLevel_08Map, marioLevel_08MapLen, 30);
			break;
		case 9:
			bg_map_32(marioLevel_09Map, marioLevel_09MapLen, 30);
			break;
		case 10:
			bg_map_32(marioLevel_10Map, marioLevel_10MapLen, 30);
			break;
		
		default:
			break;
	}
}