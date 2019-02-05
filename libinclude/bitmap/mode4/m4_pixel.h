//Plot a pixel in mode 4.

#ifndef M4_PIXEL_H
#define M4_PIXEL_H

#include <basics/types.h>
#include <bitmap/mode4/m4_defs.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void m4_pixel(u32 x, u32 y, m4_color_entry clr);

#ifdef __cplusplus
}
#endif

#endif