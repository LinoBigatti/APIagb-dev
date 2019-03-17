//Copy a tileset to the VRAM, using 16 bit units. (Not recommended)

#ifndef BG_TILESET_16_H
#define BG_TILESET_16_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <basics/tile.h>

extern void bg_tileset_16(const void *src_, u32 length, u32 cbb, u32 depth);

#ifdef __cplusplus
}
#endif

#endif
