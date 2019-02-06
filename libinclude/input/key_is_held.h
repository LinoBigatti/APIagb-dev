//See if a key is being held.

#ifndef KEY_IS_HELD_H
#define KEY_IS_HELD_H

#include <basics/types.h>
#include <IO/regions.h>
#include <input/key_defs.h>
#include <input/key_is_pressed.h>
#include <input/key_was_pressed.h>

static inline u32 key_is_held(u16 key)
{ return (key_is_pressed(key) & key_was_pressed(key)); }

#endif