//Defines for the object handlers.

#ifndef OBJ_DEFS_H
#define OBJ_DEFS_H

#include <basics/types.h>
#include <basics/mem_regs.h>

typedef struct {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    s16 fill;
} __attribute__((aligned(4))) obj_attributes;

#define obj_pal_memory ((u16*)(MEM_PAL + 0x200))

#define obj_reg_memory ((obj_attributes*)MEM_OAM)

#endif