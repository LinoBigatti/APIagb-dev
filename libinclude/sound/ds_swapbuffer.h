//Swap the main sound buffer.

#ifndef DS_SWAP_BUFFER_H
#define DS_SWAP_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sound/snd_defs.h>
#include <IO.h>
#include <DMA.h>

extern void ds_swapBuffer(void);

#ifdef __cplusplus
}
#endif

#endif