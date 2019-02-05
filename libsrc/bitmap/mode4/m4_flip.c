//Flip the mode 4 pages.

#include <bitmap/mode4/m4_flip.h>

void m4_flip(void) {
	if(m4_front_vram == m4_back_vram) { //Enable flipping
		m4_back_vram = m4_page_2;
	} else { //Flip
		IO_DISPCNT ^= dipscnt_flip;
		if(m4_front_vram == m4_page_1) {
			m4_back_vram = m4_page_1;
			m4_front_vram = m4_page_2;
		} else {
			m4_back_vram = m4_page_2;
			m4_front_vram = m4_page_1;
		}
	}
}