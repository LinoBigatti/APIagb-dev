//Mode 5 types and defines.

#ifndef M5_DEFS_H
#define M5_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/mem_regs.h>
#include <basics/types.h>

typedef u16 m5_color;

#define M5_WIDTH 160
#define M5_HEIGHT 128

extern m5_color *m5_front_vram;
extern m5_color *m5_back_vram;

#define m5_page_1 ((m5_color*)(MEM_VRAM))
#define m5_page_2 ((m5_color*)(MEM_VRAM + 0xA000))

#ifdef __cplusplus
}
#endif

#endif
