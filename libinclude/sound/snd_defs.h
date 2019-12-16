//Sound definitions.

#ifndef SOUND_DEFS_H
#define SOUND_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>

typedef enum {
    NOTE_C = 0, NOTE_CIS, NOTE_D,   NOTE_DIS, 
    NOTE_E,   NOTE_F,   NOTE_FIS, NOTE_G, 
    NOTE_GIS, NOTE_A,   NOTE_BES, NOTE_B, NOTE_S
} noteId;

extern const u32 sndRates[12];

extern const s32 octave_internal[8];

typedef enum {
    FREQ5734 = 0, 	FREQ10512,	FREQ13379,
    FREQ18157,		FREQ21024,	FREQ26758,
    FREQ31536,		FREQ36314,	FREQ40137,
    FREQ42048,		FREQ43959
} songFreqs;

#define FREQ5734_FREQ 5734
#define FREQ10512_FREQ 10512
#define FREQ13379_FREQ 13379
#define FREQ18157_FREQ 18157
#define FREQ21024_FREQ 21024
#define FREQ26758_FREQ 26758
#define FREQ31536_FREQ 31536
#define FREQ36314_FREQ 36314
#define FREQ40137_FREQ 40137
#define FREQ42048_FREQ 42048
#define FREQ43959_FREQ 43959

#define FREQ5734_TIMER 62610
#define FREQ10512_TIMER 63940
#define FREQ13379_TIMER 64282
#define FREQ18157_TIMER 64612
#define FREQ21024_TIMER 64738
#define FREQ26758_TIMER 64909
#define FREQ31536_TIMER 65004
#define FREQ36314_TIMER 65073
#define FREQ40137_TIMER 65118
#define FREQ42048_TIMER 65137
#define FREQ43959_TIMER 65154

#define FREQ5734_SIZE 96
#define FREQ10512_SIZE 176
#define FREQ13379_SIZE 224
#define FREQ18157_SIZE 304
#define FREQ21024_SIZE 352
#define FREQ26758_SIZE 448
#define FREQ31536_SIZE 528
#define FREQ36314_SIZE 608
#define FREQ40137_SIZE 672
#define FREQ42048_SIZE 704
#define FREQ43959_SIZE 736

typedef struct soundBuffer {
	s8 *bufferStart;
	s8 *freeBuffer;
	int size;
	int activeBuffer;
} soundBuffer;

extern soundBuffer mainBuffer;

typedef struct soundChannel {
	s8 *data;
	u32 pos; //20.12
	u32 inc; //20.12
	u32 vol;
	u32 length;
	u32 loop; //20.12, loop length.
} soundChannel;

extern volatile soundChannel channelA;
extern volatile soundChannel channelB;

#ifdef __cplusplus
}
#endif

#endif