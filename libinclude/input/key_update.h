//Update the key status.

#ifndef KEY_UPDATE_H
#define KEY_UPDATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <IO/regions.h>
#include <input/key_defs.h>

static inline void key_update(void) {
	previous_key = current_key;
	current_key = ~(IO_KEYINPUT) & 0x03FF;
}

#ifdef __cplusplus
}
#endif

#endif
