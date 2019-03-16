//Copy using 16 bit DMA, channel 1.

#include <DMA/dma1_16.h>

void dma1_16(const void *src, const void *dst, u32 length, u32 da, u32 sa, u32 timing, u32 other) {
	IO_DMA1CNT = 0;
	IO_DMA1SRC = (u32)(src);
	IO_DMA1DST = (u32)(dst);
	IO_DMA1CNT = dmacnt_enable | dmacnt_length(length) | da | sa | dmacnt_16 | timing | other;
}