//Mix and play sounds.

#include <sound/ds_mainmixer.h>

void ds_mainMixer(soundChannel *channels, int channelNumber) {
	s16 mixBuffer[mainBuffer.size];
	int i = 0;
	dma3_16(&i, &mixBuffer, mainBuffer.size, dmacnt_fixedsrc, dmacnt_incdst, dmacnt_inmediate, 0);

	for(int j = 0; j < channelNumber; j++) {
		if(channels[j].data != NULL) {
			for(int i = 0; i < mainBuffer.size; i++) {
				mixBuffer[i] += channels[j].data[channels[j].pos >> 12] * channels[j].vol;
				channels[j].pos += channels[j].inc;

				if(channels[j].pos >= channels[j].length) {
					if(channels[j].loop != NULL) {
						while(channels[j].pos >= channels[j].length) {
							channels[j].pos -= channels[j].loop;
						}
					} else {
						channels[j].data = NULL;
					}
				}
			}
		}
	}

	for(i = 0; i < mainBuffer.size; i++) {
		mainBuffer.freeBuffer[i] = (mixBuffer[i] >> 6) >> (channelNumber >> 1);
	}
}