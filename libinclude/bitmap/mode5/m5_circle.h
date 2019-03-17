//Draw a circle on mode 5.

#ifndef M5_CIRCLE_H
#define M5_CIRCLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode5/m5_defs.h>
#include <bitmap/mode5/m5_pixel.h>

extern void m5_circle(u32 x0, u32 y0, int radius, m5_color clr);

#ifdef __cplusplus
}
#endif

#endif
