//Types and defines for the background handlers.

#ifndef BG_DEFS_H
#define BG_DEFS_H

#include <basics/types.h>
#include <basics/mem_regs.h>

typedef u16 screen_entry;
typedef screen_entry screenblock[1024];
#define se_memory ((screenblock*)MEM_VRAM)

typedef struct {
	s16 pa;
	s16 pb;
	s16 pc;
	s16 pd;
	s32 x;
	s32 y;
} __attribute__((aligned(4))) bg_affine;

#define bg_pal_memory ((u16*)(MEM_PAL))

#define bg_aff_memory ((bg_affine*)(MEM_IO))

#endif