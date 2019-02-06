//Mode 3 types and defines.

#ifndef M3_DEFS_H
#define M3_DEFS_H

#include <basics/mem_regs.h>
#include <basics/types.h>

typedef u16 m3_color;

#define M3_WIDTH 239
#define M3_HEIGHT 159

#define m3_vram ((m3_color*)(MEM_VRAM))
#endif
