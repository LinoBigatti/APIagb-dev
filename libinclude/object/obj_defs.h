//Defines for the object handlers.

#ifndef OBJ_DEFS_H
#define OBJ_DEFS_H

#include <basics/types.h>
#include <basics/mem_regs.h>

typedef struct {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    s16 pad;
} __attribute__((aligned(4))) obj_attributes;

typedef struct {
    u16 pad0[3];
    s16 pa;
    u16 pad1[3];
    s16 pb;
    u16 pad2[3];
    s16 pc;
    u16 pad3[3];
    s16 pd;
} __attribute__((aligned(4))) obj_affine;

#define obj_pal_memory ((u16*)(MEM_PAL + 0x200))

#define obj_reg_memory ((obj_attributes*)MEM_OAM)
#define obj_aff_memory ((obj_affine*)MEM_OAM)

#endif