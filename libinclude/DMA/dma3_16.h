//Copy using 16 bit DMA, channel 3.

#ifndef DMA3_16_H
#define DMA3_16_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <IO.h>

void dma3_16(const void *src, const void *dst, u32 length, u32 da, u32 sa, u32 timing, u32 other);

#ifdef __cplusplus
}
#endif

#endif
