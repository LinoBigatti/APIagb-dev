//See if a key is pressed.

#ifndef KEY_IS_PRESSED_H
#define KEY_IS_PRESSED_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <IO/regions.h>
#include <input/key_defs.h>

static inline u32 key_is_pressed(u16 key)
{ return current_key & key; }

#ifdef __cplusplus
}
#endif

#endif
