//Load an object's tiles into VRAM, using 32 bit units. (Recommended)

#ifndef OBJ_TILES_32_H
#define OBJ_TILES_32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <basics/tile.h>

extern void obj_tiles_32(const void *src_, u32 length, u32 cb, u32 tile, u32 depth);

#ifdef __cplusplus
}
#endif

#endif
