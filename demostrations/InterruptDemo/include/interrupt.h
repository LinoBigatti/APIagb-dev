#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <basics/types.h>
#include <IO.h>
#include <bitmap/mode4/m4_defs.h>

IWRAM_CODE void interrupt(void);

#endif