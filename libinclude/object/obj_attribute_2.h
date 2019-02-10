//Attribute 2 of the 2 OAM attributes.

#ifndef OBJ_ATTR_2_H
#define OBJ_ATTR_2_H

#include <basics/types.h>

static inline u32 attr2_base_tile(u16 tile)
{ return tile & 0x1FF; }

static inline u32 attr2_priority(u8 prio)
{ return prio << 10; }

static inline u32 attr2_palbank(u8 bank)
{ return bank << 12; }

static inline u16 attr2_build(u32 tile, u32 prio, u32 bank)
{ return tile | prio | bank; }

#endif