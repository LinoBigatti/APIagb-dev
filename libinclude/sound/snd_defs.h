//Sound definitions.

#ifndef SOUND_DEFS_H
#define SOUND_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>

typedef enum {
    NOTE_C=0, NOTE_CIS, NOTE_D,   NOTE_DIS, 
    NOTE_E,   NOTE_F,   NOTE_FIS, NOTE_G, 
    NOTE_GIS, NOTE_A,   NOTE_BES, NOTE_B, NOTE_S
} noteId;

extern const u32 sndRates[12];

extern const s32 octave_internal[8];

#ifdef __cplusplus
}
#endif

#endif