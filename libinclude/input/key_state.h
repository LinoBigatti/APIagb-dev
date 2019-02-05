//See the current state of a key.

#ifndef KEY_STATE_H
#define KEY_STATE_H

#include <basics/types.h>
#include <IO/regions.h>
#include <input/key_defs.h>

static inline BOOL8 key_state(u16 key)
{ return current_key & key; }

#endif