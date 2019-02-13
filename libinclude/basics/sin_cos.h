//Fast sine and cosine functions via LUT.

#ifndef SIN_COS_H
#define SIN_COS_H

#include <basics/sin_lut.h>

static inline int fast_sin(unsigned int theta)
{ return sine_table[(theta >> 7) & 0x1FF]; }

static inline int fast_cos(unsigned int theta)
{ return sine_table[((theta >> 7) + 128) & 0x1FF]; }

#endif