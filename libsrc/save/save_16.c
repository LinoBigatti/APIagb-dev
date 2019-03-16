//Put a halfword into the save memory.

#include <save/save_16.h>

void save_16(u16 c, u32 i) {
	save_memory[i] = c & 0xFF;
	save_memory[i + 1] = (c & 0xFF00) >> 8;
}