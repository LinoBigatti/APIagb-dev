//Edit the background mosaic attributes.

#include <background/bg_mosaic.h>

u16 bg_mosaic(u32 h, u32 v) {
	return mosaic_BH(h) | mosaic_BV(v);
}