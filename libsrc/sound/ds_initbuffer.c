//Setup main sound buffer.

#include <sound/ds_initbuffer.h>

void ds_initBuffer(void *bufferStart, int bufSize) {
	mainBuffer.bufferStart = (s8*)bufferStart;
	mainBuffer.freeBuffer = bufferStart + bufSize;
	mainBuffer.size = bufSize;
}