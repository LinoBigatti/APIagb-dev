//Load a map's palette, using 32 bit units. (Recommended)

#ifndef BG_PALETTE_32_H
#define BG_PALETTE_32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <background/bg_defs.h>

extern void bg_palette_32(const void *src_, u32 length, u32 palbank);

#ifdef __cplusplus
}
#endif

#endif
