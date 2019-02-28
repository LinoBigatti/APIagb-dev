#include <basics/vsync.h>
#include <input.h>
#include <object.h>
#include <blending.h>

#include "load_title.h"
#include "load_controls.h"
#include "setup_gfx.h"
#include "globals.h"

int main(void) {
	obj_clear_all();
	
	load_title();
	
	load_controls();
	
	setup_gfx();
	
	while(1) {
		Vsync();
		
		key_update();
		
		if(key_is_pressed(BUTTON_A)) {
			if(g_alpha < 1.0) {
				g_alpha += 0.01;
			}
		} else if(key_is_pressed(BUTTON_B)) {
			if(g_alpha > 0.0) {
				g_alpha -= 0.01;
			}
		}
		
		bld_set(g_alpha);
	}
	
	return 0;
}