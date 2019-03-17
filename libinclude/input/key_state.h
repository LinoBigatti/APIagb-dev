//See the current state of a key.

#ifndef KEY_STATE_H
#define KEY_STATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <IO/regions.h>
#include <input/key_defs.h>

static inline u32 key_state(u32 key)
{ return current_key & key; }

#ifdef __cplusplus
}
#endif

#endif
