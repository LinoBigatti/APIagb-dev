//Draw a circle on mode 4.

#ifndef M4_CIRCLE_H
#define M4_CIRCLE_H

#include <basics/types.h>
#include <bitmap/mode4/m4_defs.h>
#include <bitmap/mode4/m4_pixel.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void m4_circle(u32 x0, u32 y0, int radius, m4_color_entry clr);

#ifdef __cplusplus
}
#endif

#endif