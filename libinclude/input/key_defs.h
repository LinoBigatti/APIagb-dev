//Defines for the input handlers.

#ifndef KEY_DEFS_H
#define KEY_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <IO/options.h>

#define BUTTON_A keyinput_A
#define BUTTON_B keyinput_B
#define BUTTON_SELECT keyinput_select
#define BUTTON_START keyinput_start
#define BUTTON_RIGHT keyinput_right
#define BUTTON_LEFT keyinput_left
#define BUTTON_UP keyinput_up
#define BUTTON_DOWN keyinput_down
#define BUTTON_R keyinput_R
#define BUTTON_L keyinput_L

extern u16 current_key;
extern u16 previous_key;

#ifdef __cplusplus
}
#endif

#endif
