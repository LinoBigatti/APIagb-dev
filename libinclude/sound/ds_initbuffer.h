//Setup main sound buffer.

#ifndef DS_INIT_BUFFER_H
#define DS_INIT_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <sound/snd_defs.h>

extern void ds_initBuffer(void *bufferStart, int bufSize);

#ifdef __cplusplus
}
#endif

#endif