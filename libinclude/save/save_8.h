//Put a byte into the save memory.

#ifndef SAVE_8_H
#define SAVE_8_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <save/save_defs.h>

extern void save_8(u8 c, u32 i);

#ifdef __cplusplus
}
#endif

#endif
