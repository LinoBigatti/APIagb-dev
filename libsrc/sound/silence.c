//Do a silence.

#include <sound/silence.h>

void silence(u32 length) {
	u16 snd1cnt = IO_SND1CNT;
	u16 snd2cnt = IO_SND2CNT;
	IO_SND1CNT &= !(snd1cnt_initial(15));
	IO_SND2CNT &= !(snd2cnt_initial(15));

	if((IO_IE & vblank_IRQ) != 0) {
		for(int i = 0; i < length; i++) { VBlankIntrWait(); }
	} else {
		for(int i = 0; i < length; i++) { Vsync(); }
	}

	IO_SND1CNT = snd1cnt;
	IO_SND2CNT = snd2cnt;
}