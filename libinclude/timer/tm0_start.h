//Start the timer 0.

#ifndef TM0_START_H
#define TM0_START_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <IO.h>

extern void tm0_start(u16 start, u16 freq, u16 other);

#ifdef __cplusplus
}
#endif

#endif
