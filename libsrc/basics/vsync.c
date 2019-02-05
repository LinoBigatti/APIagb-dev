//Vsync function.

#include "basics/vsync.h"

void Vsync(void) {
	while ( IO_VCOUNT >= 160 ); //VDRAW
	while ( IO_VCOUNT < 160 ); //VBLANK
}
