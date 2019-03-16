//Types and defines for functions that use tiles.

#ifndef TILE_H
#define TILE_H

#include <basics/types.h>
#include <basics/mem_regs.h>

typedef struct {
	u32 data[8];
} tile;
typedef struct {
	u32 data[16];
} tile8;

typedef tile charblock[512];
typedef tile8 charblock8[256];

#define tile_vram ((charblock*)MEM_VRAM)
#define tile8_vram ((charblock8*)MEM_VRAM)

#endif