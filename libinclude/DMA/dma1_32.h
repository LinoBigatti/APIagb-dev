//Copy using 32 bit DMA, channel 1.

#ifndef DMA1_32_H
#define DMA1_32_H

#include <basics/types.h>
#include <IO.h>

void dma1_32(const void *src, const void *dst, u32 length, u32 da, u32 sa, u32 timing, u32 other);

#endif