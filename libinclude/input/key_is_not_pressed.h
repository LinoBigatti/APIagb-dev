//See if a key isn't pressed.

#ifndef KEY_IS_NOT_PRESSED_H
#define KEY_IS_NOT_PRESSED_H

#include <basics/types.h>
#include <IO/regions.h>
#include <input/key_defs.h>

static inline BOOL8 key_is_not_pressed(u16 key)
{ return ~(current_key) & key; }

#endif