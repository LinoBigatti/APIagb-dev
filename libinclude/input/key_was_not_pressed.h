//See if a key wasn't pressed.

#ifndef KEY_WAS_NOT_PRESSED_H
#define KEY_WAS_NOT_PRESSED_H

#include <basics/types.h>
#include <IO/regions.h>
#include <input/key_defs.h>

static inline u32 key_was_not_pressed(u16 key)
{ return ~(previous_key) & key; }

#endif