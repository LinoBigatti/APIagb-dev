//Swap the main sound buffer.

#include <sound/ds_swapbuffer.h>

void ds_swapBuffer(void) {
	/* mainBuffer.activeBuffer ^= 1;
	mainBuffer.freeBuffer = (s8*)(&mainBuffer.bufferStart + mainBuffer.activeBuffer * mainBuffer.size);
	if(mainBuffer.activeBuffer == 1) { dma1_32((u32*)mainBuffer.bufferStart, (u32*)&IO_FIFOA, 0, dmacnt_fixeddst, dmacnt_incsrc, dmacnt_fifo, dmacnt_repeat); } */

	if(mainBuffer.activeBuffer == 1)	// buffer 1 just got over
   	{
       // Start playing buffer 0
      dma1_32((u32*)mainBuffer.bufferStart, (u32*)&IO_FIFOA, 0, dmacnt_fixeddst, dmacnt_incsrc, dmacnt_fifo, dmacnt_repeat);

       // Set the current buffer pointer to the start of buffer 1
      mainBuffer.freeBuffer = mainBuffer.bufferStart + mainBuffer.size;

      mainBuffer.activeBuffer = 0;
   }
   else	// buffer 0 just got over
   {
       // DMA points to buffer 1 already, so don't bother stopping and resetting it

       // Set the current buffer pointer to the start of buffer 0
      mainBuffer.freeBuffer = mainBuffer.bufferStart;
      mainBuffer.activeBuffer = 1;
   }
}