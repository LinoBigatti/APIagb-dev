//Load an object's palette, using 32 bit units. (Recommended)

#ifndef OBJ_PALETTE_32_H
#define OBJ_PALETTE_32_H

#include <basics/types.h>
#include <object/obj_defs.h>

extern void obj_palette_32(const void *src_, u32 length, u32 palbank);

#endif