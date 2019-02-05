//See if a key is stopped being pressed.

#ifndef KEY_STOP_PRESSING_H
#define KEY_STOP_PRESSING_H

#include <basics/types.h>
#include <IO/regions.h>
#include <input/key_defs.h>
#include <input/key_is_not_pressed.h>
#include <input/key_was_pressed.h>

static inline BOOL8 key_stop_pressing(u16 key)
{ return (key_is_not_pressed(key) & key_was_pressed(key)); }

#endif