//Plot a pixel in mode 3.

#ifndef M3_PIXEL_H
#define M3_PIXEL_H

#include <basics/types.h>
#include <bitmap/mode3/m3_defs.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void m3_pixel(u32 x, u32 y, m3_color clr)
{ m3_vram[x+y*M3_WIDTH] = clr; }

#ifdef __cplusplus
}
#endif

#endif