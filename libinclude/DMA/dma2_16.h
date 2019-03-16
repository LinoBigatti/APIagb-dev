//Copy using 16 bit DMA, channel 2.

#ifndef DMA2_16_H
#define DMA2_16_H

#include <basics/types.h>
#include <IO.h>

void dma2_16(const void *src, const void *dst, u32 length, u32 da, u32 sa, u32 timing, u32 other);

#endif