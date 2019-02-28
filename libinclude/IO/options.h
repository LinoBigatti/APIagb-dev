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

//IO_GREENSWAP
#define greenswap_gswap 1

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

//IO_MOSAIC
static inline u16 mosaic_BH(u16 BH)
{ return BH << 0; }
static inline u16 mosaic_BV(u16 BV)
{ return BV << 4; }
static inline u16 mosaic_OH(u16 OH)
{ return OH << 8; }
static inline u16 mosaic_OV(u16 OV)
{ return OV << 12; }

//IO_BLDCNT
#define bldcnt_ABG0 1
#define bldcnt_ABG1 1 << 1
#define bldcnt_ABG2 1 << 2
#define bldcnt_ABG3 1 << 3
#define bldcnt_AOBJ 1 << 4
#define bldcnt_ABD 1 << 5
#define bldcnt_off 0
#define bldcnt_normal 1 << 6
#define bldcnt_white 2 << 6
#define bldcnt_black 3 << 6
#define bldcnt_BBG0 1 << 8
#define bldcnt_BBG1 1 << 9
#define bldcnt_BBG2 1 << 10
#define bldcnt_BBG3 1 << 11
#define bldcnt_BOBJ 1 << 12
#define bldcnt_BBD 1 << 13

//IO_BLDALPHA
static inline u16 bldalpha_EVA(u32 EVA)
{ return (EVA << 4); }
static inline u16 bldalpha_EVB(u32 EVB)
{ return ((EVB << 4) << 8); }

//IO_BLDY
static inline u16 bldy_value(u32 value)
{ return (value << 4); }

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