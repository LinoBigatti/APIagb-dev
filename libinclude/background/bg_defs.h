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

#define BG_32x32 0
#define BG_64x32 1
#define BG_32x64 2
#define BG_64x64 3

#define BG_AFF_16x16 0
#define BG_AFF_32x32 1
#define BG_AFF_64x64 2
#define BG_AFF_128x128 3

#endif