//Mode 3 color.

#ifndef M3_COLOR_H
#define M3_COLOR_H

#include <basics/types.h>
#include <bitmap/mode3/m3_defs.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline m3_color m3_RGB_color(m3_color red, m3_color green, m3_color blue)
{ return red | (green<<5) | (blue<<10); }

#ifdef __cplusplus
}
#endif

#endif
