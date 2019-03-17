//Attribute 0 of the 2 OAM attributes.

#ifndef OBJ_ATTR_0_H
#define OBJ_ATTR_0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>

static inline u32 attr0_Y(u8 y)
{ return y; }

#define attr0_regular 0 << 8
#define attr0_affine 1 << 8
#define attr0_hide 2 << 8
#define attr0_affine_double 3 << 8

#define attr0_normal 0
#define attr0_blending 1 << 10
#define attr0_window 2 << 10

#define attr0_mosaic 1 << 12

#define attr0_4bpp 0
#define attr0_8bpp 1 << 13

#define attr0_square 0
#define attr0_horizontal_rect 1 << 14
#define attr0_vertical_rect 2 << 14

static inline u16 attr0_build(u32 y, u32 render_mode, u32 gfx_mode, u32 mosaic, u32 color_mode, u32 shape)
{ return y | render_mode | gfx_mode | mosaic | color_mode | shape; }

#ifdef __cplusplus
}
#endif

#endif
