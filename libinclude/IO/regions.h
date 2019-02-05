//Regions of the IO memory.

#ifndef IO_REGIONS_H
#define IO_REGIONS_H

#include <basics/mem_regs.h>
#include <basics/types.h>

//LCD registers.
#define IO_DISPCNT (*(u16*)(MEM_IO + 0x0000))
#define IO_DISPSTAT (*(u16*)(MEM_IO + 0x0004))
#define IO_VCOUNT (*(vu16*)(MEM_IO + 0x0006))

//Key registers.
#define IO_KEYINPUT (*(vu16*)(MEM_IO + 0x0130))
#define IO_KEYCNT (*(u16*)(MEM_IO + 0x0132))

#endif
