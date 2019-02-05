//Mode 5 color.

#ifndef M5_COLOR_H
#define M5_COLOR_H

#include <basics/types.h>
#include <bitmap/mode5/m5_defs.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline m5_color m5_RGB_color(m5_color red, m5_color green, m5_color blue)
{ return red | (green<<5) | (blue<<10); }

#ifdef __cplusplus
}
#endif

#endif
