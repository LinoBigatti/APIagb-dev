#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <basics/types.h>
#include <IO.h>
#include <sound/ds_swapbuffer.h>

IWRAM_CODE void interrupt(void);

#endif