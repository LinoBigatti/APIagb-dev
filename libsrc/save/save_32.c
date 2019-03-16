//Put a word into the save memory.

#include <save/save_32.h>

void save_32(u32 c, u32 i) {
	save_memory[i] = c & 0xFF;
	save_memory[i + 1] = (c & 0xFF00) >> 8;
	save_memory[i + 2] = (c & 0xFF0000) >> 16;
	save_memory[i + 3] = (c & 0xFF000000) >> 24;
}