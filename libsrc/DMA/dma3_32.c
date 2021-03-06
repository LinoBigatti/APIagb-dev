//Copy using 32 bit DMA, channel 3.

#include <DMA/dma3_32.h>

void dma3_32(const void *src, const void *dst, u32 length, u32 da, u32 sa, u32 timing, u32 other) {
	IO_DMA3CNT = 0;
	IO_DMA3SRC = (u32)(src);
	IO_DMA3DST = (u32)(dst);
	IO_DMA3CNT = dmacnt_enable | dmacnt_length(length) | da | sa | dmacnt_32 | timing | other;
}