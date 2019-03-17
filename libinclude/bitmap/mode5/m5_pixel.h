//Plot a pixel in mode 5.

#ifndef M5_PIXEL_H
#define M5_PIXEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode5/m5_defs.h>

static inline void m5_pixel(u32 x, u32 y, m5_color clr)
{ m5_back_vram[x+y*M5_WIDTH] = clr; }

#ifdef __cplusplus
}
#endif

#endif
