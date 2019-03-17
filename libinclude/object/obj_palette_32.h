//Load an object's palette, using 32 bit units. (Recommended)

#ifndef OBJ_PALETTE_32_H
#define OBJ_PALETTE_32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <object/obj_defs.h>

extern void obj_palette_32(const void *src_, u32 length, u32 palbank);

#ifdef __cplusplus
}
#endif

#endif
