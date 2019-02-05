//Draw a frame on mode 3.

#ifndef M3_FRAME_H
#define M3_FRAME_H

#include <basics/types.h>
#include <bitmap/mode3/m3_defs.h>
#include <bitmap/mode3/m3_line.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void m3_frame(u32 x, u32 y, u32 width, u32 height, m3_color clr);

#ifdef __cplusplus
}
#endif

#endif