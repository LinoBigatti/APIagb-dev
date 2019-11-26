//Get the rate of a note in an octave.

#include <sound/get_note_rate.h>

u32 get_note_rate(u32 note, u32 octave) {
	if(note != NOTE_S) { return 2048 - (sndRates[note] >> (octave_internal[octave] + 4)); } else { return 0; }
}