//Draw a rectangle on mode 3.

#ifndef M3_RECTANGLE_H
#define M3_RECTANGLE_H

#include <basics/types.h>
#include <bitmap/mode3/m3_defs.h>
#include <bitmap/mode3/m3_pixel.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void m3_rectangle(u32 x, u32 y, u32 width, u32 height, m3_color clr);

#ifdef __cplusplus
}
#endif

#endif