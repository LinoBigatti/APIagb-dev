//Edit the object mosaic attributes.

#include <object/obj_mosaic.h>

u16 obj_mosaic(u32 h, u32 v) {
	return mosaic_OH(h) | mosaic_OV(v);
}