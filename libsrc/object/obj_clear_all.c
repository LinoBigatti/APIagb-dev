//Clear the OAM to avoid bugs.

#include <object/obj_clear_all.h>

void obj_clear_all(void) {
	int ii;
	obj_attributes hide;
	
	hide.attr0 = attr0_hide;
	
	for(ii = 0; ii < 128; ii++) {
		obj_reg_memory[ii] = hide;
	}
}