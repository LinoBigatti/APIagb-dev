//Copy a map data using 16 bit units. (Not recommended)

#ifndef BG_MAP_16_H
#define BG_MAP_16_H

#include <basics/types.h>
#include <background/bg_defs.h>

extern void bg_map_16(const void *src_, u32 length, u32 sbb);

#endif