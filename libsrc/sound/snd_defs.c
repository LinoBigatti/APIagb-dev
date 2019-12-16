//Sound definitions.

#include <sound/snd_defs.h>

const u32 sndRates[12] = {
    8013, 7566, 7144, 6742,
    6362, 6005, 5666, 5346,
    5048, 4766, 4499, 4246
};

const s32 octave_internal[8] = {
	-2, -1, 0, 1,
	 2,  3, 4, 5
};

soundBuffer mainBuffer = {
	.bufferStart = NULL,
	.freeBuffer = NULL,
	.size = 0,
	.activeBuffer = 0
};