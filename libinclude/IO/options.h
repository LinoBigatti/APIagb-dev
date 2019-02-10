//Options for the various IO ports.

#ifndef IO_OPTIONS_H
#define IO_OPTIONS_H

#include <basics/types.h>
#include <IO/regions.h>

//IO_DSPCNT
static inline u16 dispcnt_mode(u16 mode)
{ return mode << 0; }
#define dispcnt_page_0 0
#define dispcnt_page_1 1 << 4
#define dipscnt_flip 1 << 4
#define dispcnt_hblank_free 1 << 5
#define dispcnt_obj_mapping_2D 0
#define dispcnt_obj_mapping_1D 1 << 6
#define dispcnt_forced_blank 1 << 7
#define dispcnt_BG0 1 << 8
#define dispcnt_BG1 1 << 9
#define dispcnt_BG2 1 << 10
#define dispcnt_BG3 1 << 11
#define dispcnt_OBJ 1 << 12
#define dispcnt_WIN0 1 << 13
#define dispcnt_WIN1 1 << 14
#define dispcnt_WINOBJ 1 << 15

//IO_DISPSTAT
static inline u16 dispstat_vblank(void)
{ return (IO_DISPSTAT & 1); }
static inline u16 dispstat_hblank(void)
{ return (IO_DISPSTAT & (1 << 1)) >> 1; }
static inline u16 dispstat_vcount(void)
{ return (IO_DISPSTAT & (1 << 2)) >> 2; }
#define dispstat_vblank_IRQ 1<<3
#define dispstat_hblank_IRQ 1<<4
#define dispstat_vcount_IRQ 1<<5
static inline u16 dispstat_vcount_setting(u16 setting)
{ return setting << 8; }

//IO_BG0CNT
static inline u16 bg0cnt_prio(u16 prio)
{ return prio << 0; }
static inline u16 bg0cnt_cbb(u16 cbb)
{ return cbb << 2; }
#define bg0cnt_mosaic 1 << 6
#define bg0cnt_4bpp 0 << 7
#define bg0cnt_8bpp 1 << 7
static inline u16 bg0cnt_sbb(u16 sbb)
{ return sbb << 8; }
static inline u16 bg0cnt_size(u16 size)
{ return size << 14; }

//IO_BG1CNT
static inline u16 bg1cnt_prio(u16 prio)
{ return prio << 0; }
static inline u16 bg1cnt_cbb(u16 cbb)
{ return cbb << 2; }
#define bg1cnt_mosaic 1 << 6
#define bg1cnt_4bpp 0 << 7
#define bg1cnt_8bpp 1 << 7
static inline u16 bg1cnt_sbb(u16 sbb)
{ return sbb << 8; }
static inline u16 bg1cnt_size(u16 size)
{ return size << 14; }

//IO_BG2CNT
static inline u16 bg2cnt_prio(u16 prio)
{ return prio << 0; }
static inline u16 bg2cnt_cbb(u16 cbb)
{ return cbb << 2; }
#define bg2cnt_mosaic 1 << 6
#define bg2cnt_4bpp 0 << 7
#define bg2cnt_8bpp 1 << 7
static inline u16 bg2cnt_sbb(u16 sbb)
{ return sbb << 8; }
#define bg2cnt_wraparound 1 << 13
static inline u16 bg2cnt_size(u16 size)
{ return size << 14; }

//IO_BG3CNT
static inline u16 bg3cnt_prio(u16 prio)
{ return prio << 0; }
static inline u16 bg3cnt_cbb(u16 cbb)
{ return cbb << 2; }
#define bg3cnt_mosaic 1 << 6
#define bg3cnt_4bpp 0 << 7
#define bg3cnt_8bpp 1 << 7
static inline u16 bg3cnt_sbb(u16 sbb)
{ return sbb << 8; }
#define bg3cnt_wraparound 1 << 13
static inline u16 bg3cnt_size(u16 size)
{ return size << 14; }

//IO_KEYINPUT
#define keyinput_A 1
#define keyinput_B 1 << 1
#define keyinput_select 1 << 2
#define keyinput_start 1 << 3
#define keyinput_right 1 << 4
#define keyinput_left 1 << 5
#define keyinput_up 1 << 6
#define keyinput_down 1 << 7
#define keyinput_R 1 << 8
#define keyinput_L 1 << 9

#endif