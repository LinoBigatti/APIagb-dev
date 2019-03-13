//Put a byte into the save memory.

#include <save/save_8.h>

void save_8(u8 c, u32 i) {
	save_memory[i] = c;
}