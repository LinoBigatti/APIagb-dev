//Copy a map data using 32 bit units. (Recommended)

#ifndef BG_MAP_32_H
#define BG_MAP_32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <background/bg_defs.h>

extern void bg_map_32(const void *src_, u32 length, u32 sbb);

#ifdef __cplusplus
}
#endif

#endif
