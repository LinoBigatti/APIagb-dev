//Draw a line in mode 3

#ifndef M3_LINE_H
#define M3_LINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode3/m3_defs.h>
#include <bitmap/mode3/m3_pixel.h>

extern void m3_line(u32 x1, u32 y1, u32 x2, u32 y2, m3_color clr);

#ifdef __cplusplus
}
#endif

#endif
