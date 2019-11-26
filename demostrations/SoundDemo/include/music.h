//Beep boop.

#ifndef MUSIC_H
#define MUSIC_H

#include <basics/types.h>
#include <basics/bios.h>
#include <sound/snd_defs.h>
#include <sound/get_note_rate.h>
#include <sound/silence.h>
#include <IO.h>

u32 octave;

void delay(u32 cycles);

#define playNote(note, octave) IO_SND1FREQ = snd1freq_rate(get_note_rate(note, octave)) | snd1freq_reset

void (*songs[16])();

void musicalScale(void);

void octaveScale(void);

void happyBirthday(void);

void TTLS(void);

void snake(void); //How the fuck is this called lmao.

void SMBoverworld(void);

#endif