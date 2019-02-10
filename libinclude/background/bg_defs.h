//Types and defines for the background handlers.

#ifndef BG_DEFS_H
#define BG_DEFS_H

#include <basics/types.h>
#include <basics/mem_regs.h>

typedef u16 screen_entry;
typedef screen_entry screenblock[1024];
#define se_memory ((screenblock*)MEM_VRAM)

#define bg_pal_memory ((u16*)(MEM_PAL))

#endif