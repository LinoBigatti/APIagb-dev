//Options for the various IO ports.

#ifndef IO_OPTIONS_H
#define IO_OPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

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

//IO_WIN0H
static inline u16 win0h_right(u8 right)
{ return right; }
static inline u16 win0h_left(u8 left)
{ return left << 8; }

//IO_WIN0V
static inline u16 win0v_bottom(u8 bottom)
{ return bottom; }
static inline u16 win0v_top(u8 top)
{ return top << 8; }

//IO_WIN1H
static inline u16 win1h_right(u8 right)
{ return right; }
static inline u16 win1h_left(u8 left)
{ return left << 8; }

//IO_WIN1V
static inline u16 win1v_bottom(u8 bottom)
{ return bottom; }
static inline u16 win1v_top(u8 top)
{ return top << 8; }

//IO_WININ
#define winin_win0BG0 1
#define winin_win0BG1 1 << 1
#define winin_win0BG2 1 << 2
#define winin_win0BG3 1 << 3
#define winin_win0OBJ 1 << 4
#define winin_win0BLD 1 << 5
static inline u16 winin_win0(u16 bg0, u16 bg1, u16 bg2, u16 bg3, u16 obj, u16 bld)
{ return bg0 | bg1 | bg2 | bg3 | obj | bld; }
#define winin_win1BG0 1 << 8
#define winin_win1BG1 1 << 9
#define winin_win1BG2 1 << 10
#define winin_win1BG3 1 << 11
#define winin_win1OBJ 1 << 12
#define winin_win1BLD 1 << 13
static inline u16 winin_win1(u16 bg0, u16 bg1, u16 bg2, u16 bg3, u16 obj, u16 bld)
{ return bg0 | bg1 | bg2 | bg3 | obj | bld; }

//IO_WINOUT
#define winout_winoutBG0 1
#define winout_winoutBG1 1 << 1
#define winout_winoutBG2 1 << 2
#define winout_winoutBG3 1 << 3
#define winout_winoutOBJ 1 << 4
#define winout_winoutBLD 1 << 5
static inline u16 winout_winout(u16 bg0, u16 bg1, u16 bg2, u16 bg3, u16 obj, u16 bld)
{ return bg0 | bg1 | bg2 | bg3 | obj | bld; }
#define winout_winobjBG0 1 << 8
#define winout_winobjBG1 1 << 9
#define winout_winobjBG2 1 << 10
#define winout_winobjBG3 1 << 11
#define winout_winobjOBJ 1 << 12
#define winout_winobjBLD 1 << 13
static inline u16 winout_winobj(u16 bg0, u16 bg1, u16 bg2, u16 bg3, u16 obj, u16 bld)
{ return bg0 | bg1 | bg2 | bg3 | obj | bld; }

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

//IO_DMAxCNT
static inline u32 dmacnt_length(u32 length)
{ return length; }
#define dmacnt_incdst 0
#define dmacnt_decdst 1 << 21
#define dmacnt_fixeddst 2 << 21
#define dmacnt_resetdst 3 << 21
#define dmacnt_incsrc 0
#define dmacnt_decsrc 1 << 23
#define dmacnt_fixedsrc 2 << 23
#define dmacnt_repeat 1 << 25
#define dmacnt_16 0
#define dmacnt_32 1 << 26
#define dmacnt_inmediate 0
#define dmacnt_vblank 1 << 28
#define dmacnt_hblank 2 << 28
#define dmacnt_fifo 3 << 28
#define dmacnt_IRQ 1 << 30
#define dmacnt_enable 1 << 31

//IO_TM0DATA
static inline u16 tm0data_read(void)
{ return IO_TM0DATA; }
static inline u16 tm0data_start(u16 start)
{ return start; }

//IO_TM1DATA
static inline u16 tm1data_read(void)
{ return IO_TM1DATA; }
static inline u16 tm1data_start(u16 start)
{ return start; }

//IO_TM2DATA
static inline u16 tm2data_read(void)
{ return IO_TM2DATA; }
static inline u16 tm2data_start(u16 start)
{ return start; }

//IO_TM3DATA
static inline u16 tm3data_read(void)
{ return IO_TM3DATA; }
static inline u16 tm3data_start(u16 start)
{ return start; }

//IO_TMCNT
#define tmcnt_freq_1 0
#define tmcnt_freq_64 1
#define tmcnt_freq_256 2
#define tmcnt_freq_1024 3
#define tmcnt_cascade 1 << 2
#define tmcnt_IRQ 1 << 6
#define tmcnt_enable 1 << 7

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

//IO_IE & IO_IF & IO_IFBIOS
#define vblank_IRQ 1
#define hblank_IRQ 1 << 1
#define vcount_IRQ 1 << 2
#define timer0_IRQ 1 << 3
#define timer1_IRQ 1 << 4
#define timer2_IRQ 1 << 5
#define timer3_IRQ 1 << 6
#define serial_IRQ 1 << 7
#define DMA0_IRQ 1 << 8
#define DMA1_IRQ 1 << 9
#define DMA2_IRQ 1 << 10
#define DMA3_IRQ 1 << 11
#define keypad_IRQ 1 << 12
#define cartridge_IRQ 1 << 13

//IO_IME
#define ime_enable 1

#ifdef __cplusplus
}
#endif

#endif
