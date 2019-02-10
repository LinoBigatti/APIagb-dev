//Load a map's palette, using 16 bit units. (Not recommended)

#ifndef BG_PALETTE_16_H
#define BG_PALETTE_16_H

#include <basics/types.h>
#include <background/bg_defs.h>

extern void bg_palette_16(const void *src_, u32 length, u32 palbank);

#endif