//Attribute 1 of the 2 OAM attributes.

#ifndef OBJ_ATTR_1_H
#define OBJ_ATTR_1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>

static inline u32 attr1_X(u16 x)
{ return x & 0x1FF; }

static inline u32 attr1_aff_index(u8 index)
{ return index << 9; }

#define attr1_hflip 1 << 12
#define attr1_vflip 1 << 13

static inline u32 attr1_size(u8 size)
{ return size << 14; }

static inline u16 attr1_regular_build(u32 x, u32 hflip, u32 vflip, u32 size)
{ return x | hflip | vflip | size; }

static inline u16 attr1_affine_build(u32 x, u32 aff_index, u32 size)
{ return x | aff_index | size; }

#ifdef __cplusplus
}
#endif

#endif
