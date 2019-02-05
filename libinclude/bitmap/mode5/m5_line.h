//Draw a line in mode 5.

#ifndef M5_LINE_H
#define M5_LINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode5/m5_defs.h>
#include <bitmap/mode5/m5_pixel.h>

extern void m5_line(u32 x1, u32 y1, u32 x2, u32 y2, m5_color clr);

#ifdef __cplusplus
}
#endif

#endif
