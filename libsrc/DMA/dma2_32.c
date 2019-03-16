//Copy using 32 bit DMA, channel 2.

#include <DMA/dma2_32.h>

void dma2_32(const void *src, const void *dst, u32 length, u32 da, u32 sa, u32 timing, u32 other) {
	IO_DMA2CNT = 0;
	IO_DMA2SRC = (u32)(src);
	IO_DMA2DST = (u32)(dst);
	IO_DMA2CNT = dmacnt_enable | dmacnt_length(length) | da | sa | dmacnt_32 | timing | other;
}