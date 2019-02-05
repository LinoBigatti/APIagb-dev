//See if a key was pressed.

#ifndef KEY_WAS_PRESSED_H
#define KEY_WAS_PRESSED_H

#include <basics/types.h>
#include <IO/regions.h>
#include <input/key_defs.h>

static inline BOOL8 key_was_pressed(u16 key)
{ return previous_key & key; }

#endif