//GBA memory regions.

#ifndef MEM_REGS_H
#define MEM_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>

#define MEM_BIOS 0x00000000
#define MEM_EWRAM 0x02000000
#define MEM_IWRAM 0x03000000
#define MEM_IO 0x04000000
#define MEM_PAL 0x05000000
#define MEM_VRAM 0x06000000
#define MEM_OAM 0x07000000
#define MEM_ROM_WS0 0x08000000
#define MEM_ROM_WS1 0x0A000000
#define MEM_ROM_WS2 0x0C000000
#define MEM_SAVE 0x0E000000

#ifdef __cplusplus
}
#endif

#endif
