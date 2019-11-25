//Get the rate of a note in an octave.

#ifndef GET_NOTE_RATE_H
#define GET_NOTE_RATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <sound/snd_defs.h>

u32 get_note_rate(u32 note, u32 octave);

#ifdef __cplusplus
}
#endif

#endif