//Beep boop.

#include "music.h"

u32 octave = 0;

void delay(u32 cycles) {
	for(int i = 0; i < cycles; i++) {
		VBlankIntrWait();
	}
}

void (*songs[8])() = {
	musicalScale,
	octaveScale,
	happyBirthday,
	TTLS,
	snake,
	SMBoverworld,
	OTJ,
	TLOZoverworld
};

void playTune(u32 *notes, u32 *lengths, u32 *octaves, u32 length) {
	for(int i = 0; i < length; i++) {
		if(notes[i] != NOTE_S) { 
			playNote(notes[i], octaves[i]);
			delay(lengths[i]);
		} else {
			silence(lengths[i]);
		}
	}
}

void musicalScale(void) {
	playNote(NOTE_C, octave);
	delay(30);
	playNote(NOTE_D, octave);
	delay(30);
	playNote(NOTE_E, octave);
	delay(30);
	playNote(NOTE_F, octave);
	delay(30);
	playNote(NOTE_G, octave);
	delay(30);
	playNote(NOTE_A, octave);
	delay(30);
	playNote(NOTE_B, octave);
	delay(30);
	if(octave != 7) { playNote(NOTE_C, octave + 1); }
	delay(30);
}

void octaveScale(void) {
	playNote(NOTE_C, 0);
	delay(30);
	playNote(NOTE_C, 1);
	delay(30);
	playNote(NOTE_C, 2);
	delay(30);
	playNote(NOTE_C, 3);
	delay(30);
	playNote(NOTE_C, 4);
	delay(30);
	playNote(NOTE_C, 5);
	delay(30);
	playNote(NOTE_C, 6);
	delay(30);
	playNote(NOTE_C, 7);
	delay(30);
}

void happyBirthday(void) {
	playNote(NOTE_C, 3);
	delay(15);
	playNote(NOTE_C, 3);
	delay(15);
	playNote(NOTE_D, 3);
	delay(30);
	playNote(NOTE_C, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(30);
	playNote(NOTE_E, 3);
	delay(60);

	playNote(NOTE_C, 3);
	delay(15);
	playNote(NOTE_C, 3);
	delay(15);
	playNote(NOTE_D, 3);
	delay(30);
	playNote(NOTE_C, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(60);

	playNote(NOTE_C, 3);
	delay(15);
	playNote(NOTE_C, 3);
	delay(15);
	playNote(NOTE_C, 4);
	delay(30);
	playNote(NOTE_A, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(15);
	playNote(NOTE_F, 3);
	delay(15);
	playNote(NOTE_E, 3);
	delay(30);
	playNote(NOTE_D, 3);
	delay(30);

	playNote(NOTE_BES, 3);
	delay(15);
	playNote(NOTE_BES, 3);
	delay(15);
	playNote(NOTE_A, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(60);
}

void TTLS(void) {
	playNote(NOTE_C, 3);
	delay(30);
	playNote(NOTE_C, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_A, 3);
	delay(30);
	playNote(NOTE_A, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(60);

	playNote(NOTE_F, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(30);
	playNote(NOTE_E, 3);
	delay(30);
	playNote(NOTE_E, 3);
	delay(30);
	playNote(NOTE_D, 3);
	delay(30);
	playNote(NOTE_D, 3);
	delay(30);
	playNote(NOTE_C, 3);
	delay(60);

	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(30);
	playNote(NOTE_E, 3);
	delay(30);
	playNote(NOTE_E, 3);
	delay(30);
	playNote(NOTE_D, 3);
	delay(60);

	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(30);
	playNote(NOTE_F, 3);
	delay(30);
	playNote(NOTE_E, 3);
	delay(30);
	playNote(NOTE_E, 3);
	delay(30);
	playNote(NOTE_D, 3);
	delay(60);

	playNote(NOTE_C, 3);
	delay(30);
	playNote(NOTE_C, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(30);
	playNote(NOTE_A, 3);
	delay(30);
	playNote(NOTE_A, 3);
	delay(30);
	playNote(NOTE_G, 3);
	delay(60);

	playNote(NOTE_F, 3);
	delay(40);
	playNote(NOTE_F, 3);
	delay(40);
	playNote(NOTE_E, 3);
	delay(50);
	playNote(NOTE_E, 3);
	delay(50);
	playNote(NOTE_D, 3);
	delay(60);
	playNote(NOTE_D, 3);
	delay(60);
	playNote(NOTE_C, 3);
	delay(120);
}

u32 snakeNotes[23] = {
	NOTE_D, NOTE_E, NOTE_F, NOTE_E, NOTE_D,
	NOTE_D, NOTE_E, NOTE_F, NOTE_A, NOTE_F, NOTE_E, NOTE_D,
	NOTE_E, NOTE_F, NOTE_E, NOTE_D,
	NOTE_D, NOTE_E, NOTE_F, NOTE_A, NOTE_E, NOTE_F, NOTE_D
};

u32 snakeLengths[23] = {
	15, 15, 30, 30, 30,
	15, 15, 15, 15, 15, 15, 45,
	15, 45, 15, 30,
	15, 15, 15, 45, 30, 30, 60
};

u32 snakeOctaves[23] = {
	3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3,
};

void snake(void) {
	playTune((u32*)&snakeNotes, (u32*)&snakeLengths, (u32*)&snakeOctaves, 23);
}

u32 SMBoverworldNotes[33] = {
	NOTE_E, NOTE_E, NOTE_E, NOTE_S, NOTE_C, NOTE_E, NOTE_G, NOTE_G,
	NOTE_C, NOTE_S, NOTE_G, NOTE_S, NOTE_E, NOTE_S, NOTE_A, NOTE_S, NOTE_B, NOTE_S, NOTE_BES, NOTE_A,
	NOTE_G, NOTE_E, NOTE_G, NOTE_S, NOTE_A, NOTE_F, NOTE_G, NOTE_E, NOTE_S, NOTE_C, NOTE_S, NOTE_D, NOTE_B
};

u32 SMBoverworldLengths[33] = {
	7, 15, 7, 7, 7, 15, 30, 30,
	15, 7, 7, 15, 15, 7, 7, 7, 7, 7, 7, 15,
	7, 7, 7, 7, 15, 7, 7, 7, 7, 7, 7, 7, 7
};

u32 SMBoverworldOctaves[33] = {
	4, 4, 4, 0, 4, 4, 4, 3,
	4, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 3,
	3, 4, 4, 0, 4, 4, 4, 4, 0, 4, 0, 4, 3
};

void SMBoverworld(void) {
	playTune((u32*)&SMBoverworldNotes, (u32*)&SMBoverworldLengths, (u32*)&SMBoverworldOctaves, 33);
}

u32 OTJNotes[58] = {
	NOTE_E, NOTE_F, NOTE_G,
	NOTE_G, NOTE_F, NOTE_E, NOTE_D,
	NOTE_C, NOTE_C, NOTE_D, NOTE_E,
	NOTE_E, NOTE_D, NOTE_D,
	NOTE_E, NOTE_F, NOTE_G,
	NOTE_G, NOTE_F, NOTE_E, NOTE_D,
	NOTE_C, NOTE_C, NOTE_D, NOTE_E,
	NOTE_D, NOTE_C, NOTE_C,
	NOTE_C, NOTE_E, NOTE_C,
	NOTE_D, NOTE_E, NOTE_F, NOTE_E, NOTE_C,
	NOTE_D, NOTE_E, NOTE_F, NOTE_E, NOTE_D,
	NOTE_C, NOTE_D, NOTE_D,
	NOTE_E, NOTE_F, NOTE_G,
	NOTE_G, NOTE_F, NOTE_E, NOTE_D,
	NOTE_C, NOTE_C, NOTE_D, NOTE_E,
	NOTE_D, NOTE_C, NOTE_C
};

u32 OTJLengths[58] = {
	60, 30, 30,
	30, 30, 30, 30,
	30, 30, 30, 30,
	45, 15, 60,
	60, 30, 30,
	30, 30, 30, 30,
	30, 30, 30, 30,
	45, 15, 60,
	60, 30, 30,
	30, 15, 15, 30, 30,
	30, 15, 15, 30, 30,
	30, 30, 60,
	60, 30, 30,
	30, 30, 30, 30,
	30, 30, 30, 30,
	45, 15, 60,
};

u32 OTJOctaves[58] = {
	3, 3, 3,
	3, 3, 3, 3,
	3, 3, 3, 3,
	3, 3, 3,
	3, 3, 3,
	3, 3, 3, 3,
	3, 3, 3, 3,
	3, 3, 3,
	3, 3, 3,
	3, 3, 3, 3, 3,
	3, 3, 3, 3, 3,
	3, 3, 3,
	3, 3, 3,
	3, 3, 3, 3,
	3, 3, 3, 3,
	3, 3, 3,
};

void OTJ(void) {
	playTune((u32*)&OTJNotes, (u32*)&OTJLengths, (u32*)&OTJOctaves, 58);
}

u32 TLOZoverworldNotes[57] = {
	NOTE_BES, NOTE_BES, NOTE_F, NOTE_F, NOTE_BES, 
	NOTE_GIS, NOTE_FIS, NOTE_GIS, 
	NOTE_BES, NOTE_BES, NOTE_F, NOTE_F, NOTE_BES, 
	NOTE_GIS, NOTE_FIS, NOTE_GIS, 
	NOTE_S,
	NOTE_BES, NOTE_F, NOTE_F, NOTE_BES, NOTE_BES, NOTE_B, NOTE_D, NOTE_DIS, 
	NOTE_F, NOTE_F, NOTE_F, NOTE_F, NOTE_G, NOTE_A,
	NOTE_C, NOTE_C, NOTE_C, NOTE_C, NOTE_B, NOTE_A,
	NOTE_B, NOTE_A, NOTE_G, NOTE_G,
	NOTE_E, NOTE_F, NOTE_G, NOTE_G, NOTE_F, NOTE_E, 
	NOTE_D, NOTE_E, NOTE_F, NOTE_F, NOTE_E, NOTE_D,
	NOTE_C, NOTE_D, NOTE_E, NOTE_F
};

u32 TLOZoverworldLengths[57] = {
	60, 15, 15, 15, 15,
	7, 7, 60,
	60, 15, 15, 15, 15,
	7, 7, 60,
	60,
	30, 30, 15, 15, 7, 7, 7, 7,
	60, 15, 15, 15, 15, 15,
	60, 15, 15, 15, 15, 15,
	15, 15, 60, 30,
	15, 15, 30, 30, 15, 15,
	15, 15, 30, 30, 15, 15,
	15, 15, 60, 30
};

u32 TLOZoverworldOctaves[57] = {
	3, 3, 3, 3, 3,
	3, 3, 3,
	3, 3, 3, 3, 3,
	3, 3, 3,
	0,
	3, 3, 3, 3, 3, 4, 4, 4, 
	4, 4, 4, 4, 4, 4,
	5, 5, 5, 5, 4, 4,  
	4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4
};

void TLOZoverworld(void) {
	playTune((u32*)&TLOZoverworldNotes, (u32*)&TLOZoverworldLengths, (u32*)&TLOZoverworldOctaves, 57);
}