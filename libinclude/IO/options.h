//Options for the various IO ports.

#ifndef IO_OPTIONS_H
#define IO_OPTIONS_H

#include <basics/types.h>
#include <IO/regions.h>

//IO_DSPCNT
static inline u16 dispcnt_mode(u16 mode)
{ return mode<<0; }
#define dispcnt_page_0 0
#define dispcnt_page_1 1<<4
#define dipscnt_flip 1<<4
#define dispcnt_hblank_free 1<<5
#define dispcnt_obj_mapping_2D 0
#define dispcnt_obj_mapping_1D 1<<6
#define dispcnt_forced_blank 1<<7
#define dispcnt_BG0 1<<8
#define dispcnt_BG1 1<<9
#define dispcnt_BG2 1<<10
#define dispcnt_BG3 1<<11
#define dispcnt_OBJ 1<<12
#define dispcnt_WIN0 1<<13
#define dispcnt_WIN1 1<<14
#define dispcnt_WINOBJ 1<<15

//IO_KEYINPUT
#define keyinput_A 1
#define keyinput_B 1<<1
#define keyinput_select 1<<2
#define keyinput_start 1<<3
#define keyinput_right 1<<4
#define keyinput_left 1<<5
#define keyinput_up 1<<6
#define keyinput_down 1<<7
#define keyinput_R 1<<8
#define keyinput_L 1<<9

#endif