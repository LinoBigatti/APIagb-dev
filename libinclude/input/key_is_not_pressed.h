//See if a key isn't pressed.

#ifndef KEY_IS_NOT_PRESSED_H
#define KEY_IS_NOT_PRESSED_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <IO/regions.h>
#include <input/key_defs.h>

static inline u32 key_is_not_pressed(u16 key)
{ return ~(current_key) & key; }

#ifdef __cplusplus
}
#endif

#endif
