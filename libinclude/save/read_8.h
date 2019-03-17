//Read a byte from the save memory.

#ifndef READ_8_H
#define READ_8_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <save/save_defs.h>

extern u8 read_8(u32 i);

#ifdef __cplusplus
}
#endif

#endif
