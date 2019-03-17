//Put a halfword into the save memory.

#ifndef SAVE_16_H
#define SAVE_16_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <save/save_defs.h>

extern void save_16(u16 c, u32 i);

#ifdef __cplusplus
}
#endif

#endif
