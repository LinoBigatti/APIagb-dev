//Mix and play sounds.

#ifndef DS_MAINMIXER_H
#define DS_MAINMIXER_H

#include <basics/types.h>
#include <IO.h>
#include <DMA/dma3_16.h>
#include <sound/snd_defs.h>

extern void ds_mainMixer(soundChannel *channels, int channelNumber);

#endif