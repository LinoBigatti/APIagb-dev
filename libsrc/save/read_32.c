//Read a word from the save memory.

#include <save/read_32.h>

u32 read_32(u32 i) {
	return (save_memory[i + 3] << 24) | (save_memory[i + 2] << 16) | (save_memory[i + 1] << 8) | save_memory[i];
}