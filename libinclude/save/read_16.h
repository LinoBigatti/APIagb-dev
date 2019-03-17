//Read a halfword from the save memory.

#ifndef READ_16_H
#define READ_16_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <save/save_defs.h>

extern u16 read_16(u32 i);

#ifdef __cplusplus
}
#endif

#endif
