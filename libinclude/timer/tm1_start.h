//Start the timer 1.

#ifndef TM1_START_H
#define TM1_START_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <IO.h>

extern void tm1_start(u16 start, u16 freq, u16 other);

#ifdef __cplusplus
}
#endif

#endif
