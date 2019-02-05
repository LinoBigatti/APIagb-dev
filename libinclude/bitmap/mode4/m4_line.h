//Draw a line in mode 4.

#ifndef M4_LINE_H
#define M4_LINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode4/m4_defs.h>
#include <bitmap/mode4/m4_pixel.h>

extern void m4_line(u32 x1, u32 y1, u32 x2, u32 y2, m4_color_entry clr);

#ifdef __cplusplus
}
#endif

#endif
