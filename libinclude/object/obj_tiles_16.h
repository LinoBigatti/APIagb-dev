//Load an object's tiles into VRAM, using 16 bit units. (Not recommended)

#ifndef OBJ_TILES_16_H
#define OBJ_TILES_16_H

#include <basics/types.h>
#include <basics/tile.h>

extern void obj_tiles_16(const void *src_, u32 length, u32 cb, u32 tile, u32 depth);

#endif