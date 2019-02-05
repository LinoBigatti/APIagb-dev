//Update the key status.

#ifndef KEY_UPDATE_H
#define KEY_UPDATE_H

#include <IO/regions.h>
#include <input/key_defs.h>

static inline void key_update(void) {
	previous_key = current_key;
	current_key = ~(IO_KEYINPUT);
}

#endif