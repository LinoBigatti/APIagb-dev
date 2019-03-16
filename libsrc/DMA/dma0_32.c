//Copy using 32 bit DMA, channel 0.

#include <DMA/dma0_32.h>

void dma0_32(const void *src, const void *dst, u32 length, u32 da, u32 sa, u32 timing, u32 other) {
	IO_DMA0CNT = 0;
	IO_DMA0SRC = (u32)(src);
	IO_DMA0DST = (u32)(dst);
	IO_DMA0CNT = dmacnt_enable | dmacnt_length(length) | da | sa | dmacnt_32 | timing | other;
}