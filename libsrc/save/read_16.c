//Read a halfword from the save memory.

#include <save/read_16.h>

u16 read_16(u32 i) {
	return (save_memory[i + 1] << 8) | save_memory[i];
}