//Load an object's palette, using 16 bit units. (Not recommended)

#ifndef OBJ_PALETTE_16_H
#define OBJ_PALETTE_16_H

#include <basics/types.h>
#include <object/obj_defs.h>

extern void obj_palette_16(const void *src_, u32 length, u32 palbank);

#endif