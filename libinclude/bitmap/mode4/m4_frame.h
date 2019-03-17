//Draw a frame on mode 4.

#ifndef M4_FRAME_H
#define M4_FRAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode4/m4_defs.h>
#include <bitmap/mode4/m4_line.h>

extern void m4_frame(u32 x, u32 y, u32 width, u32 height, m4_color_entry clr);

#ifdef __cplusplus
}
#endif

#endif
