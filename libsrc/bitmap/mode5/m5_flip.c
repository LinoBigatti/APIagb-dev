//Flip the mode 5 pages.

#include <bitmap/mode5/m5_flip.h>

void m5_flip(void) {
	if(m5_front_vram == m5_back_vram) { //Enable flipping
		m5_back_vram = m5_page_2;
	} else { //Flip
		IO_DISPCNT ^= dipscnt_flip;
		if(m5_front_vram == m5_page_1) {
			m5_back_vram = m5_page_1;
			m5_front_vram = m5_page_2;
		} else {
			m5_back_vram = m5_page_2;
			m5_front_vram = m5_page_1;
		}
	}
}