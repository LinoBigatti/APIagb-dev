//Load graphics.

#ifndef GFX_H
#define GFX_H

#include <basics/types.h>
#include <basics/bios.h>
#include <basics/tile.h>
#include <IO.h>
#include <background/bg_defs.h>

#include "BGshared.h"

#include "song1.h"
#include "song2.h"
#include "song3.h"
#include "song4.h"
#include "song5.h"
#include "song6.h"
#include "song7.h"
#include "song8.h"

int sbb;

void loadGFX(void);

void nextScreen(void);

void prevScreen(void);

void setScreen(int sbb_);

#endif