//Read a byte from the save memory.

#include <save/read_8.h>

u8 read_8(u32 i) {
	return save_memory[i];
}