//Draw a circle on mode 3.

#ifndef M3_CIRCLE_H
#define M3_CIRCLE_H

#include <basics/types.h>
#include <bitmap/mode3/m3_defs.h>
#include <bitmap/mode3/m3_pixel.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void m3_circle(u32 x0, u32 y0, int radius, m3_color clr);

#ifdef __cplusplus
}
#endif

#endif