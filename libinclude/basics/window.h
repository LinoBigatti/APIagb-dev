//Control the window feature of the GBA.

#ifndef WINDOW_H
#define WINDOW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <IO.h>

static inline void win0_build(u8 x, u8 y, u8 w, u8 h)
{ u8 r = x + w, b = y + h;
  IO_WIN0H = win0h_right(r) | win0h_left(x);
  IO_WIN0V = win0v_bottom(b) | win0v_top(y); }

static inline void win1_build(u16 x, u16 y, u16 w, u16 h)
{ u16 r = x + w, b = y + h;
  IO_WIN1H = win1h_right(r) | win1h_left(x);
  IO_WIN1V = win1v_bottom(b) | win1v_top(y); }

#ifdef __cplusplus
}
#endif

#endif
