//Mode 3 color.

#ifndef M3_COLOR_H
#define M3_COLOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode3/m3_defs.h>

static inline m3_color m3_RGB_color(m3_color red, m3_color green, m3_color blue)
{ return red | (green<<5) | (blue<<10); }

#ifdef __cplusplus
}
#endif

#endif
