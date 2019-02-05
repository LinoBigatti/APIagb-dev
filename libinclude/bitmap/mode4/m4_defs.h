//Mode 4 types and defines.

#ifndef M4_DEFS_H
#define M4_DEFS_H

#include <basics/mem_regs.h>
#include <basics/types.h>

typedef u8 m4_color_entry;

#define M4_WIDTH 240
#define M4_HEIGHT 160

extern u16 *m4_front_vram;
extern u16 *m4_back_vram;

#define m4_page_1 ((u16*)(MEM_VRAM))
#define m4_page_2 ((u16*)(MEM_VRAM + 0xA000))

#define m4_pal_memory ((u16*)(MEM_PAL))

#endif