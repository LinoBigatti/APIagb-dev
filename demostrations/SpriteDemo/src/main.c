#include <basics/types.h>
#include <basics/vsync.h>
#include <basics/tile.h>
#include <IO.h>
#include <input.h>
#include <object.h>

#include "mario.h"
#include "marioPal.h"

int main(void) {
	obj_clear_all();
	
	obj_tiles_32(marioTiles, marioTilesLen / 4, 4, 0, 4);
	
	obj_palette_32(marioPalette, 0);
	
	IO_DISPCNT = dispcnt_OBJ | dispcnt_obj_mapping_1D;
	
	obj_attributes *mario = &obj_reg_memory[0];
	
	mario->attr0 = attr0_build(attr0_Y(0), attr0_regular, attr0_normal, 0, attr0_4bpp, attr0_square);
	mario->attr1 = attr1_regular_build(attr1_X(0), 0, 0, attr1_size(1));
	mario->attr2 = attr2_build(attr2_base_tile(0), attr2_priority(0), attr2_palbank(0));
	
	while(1) {
		Vsync();
	}
	
	return 0;
}
