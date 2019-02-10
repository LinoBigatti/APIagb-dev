//Regions of the IO memory.

#ifndef IO_REGIONS_H
#define IO_REGIONS_H

#include <basics/mem_regs.h>
#include <basics/types.h>

//LCD registers.
#define IO_DISPCNT (*(u16*)(MEM_IO + 0x0000))
#define IO_DISPSTAT (*(vu16*)(MEM_IO + 0x0004))
#define IO_VCOUNT (*(vu16*)(MEM_IO + 0x0006))
#define IO_BG0CNT (*(u16*)(MEM_IO + 0x0008))
#define IO_BG1CNT (*(u16*)(MEM_IO + 0x000A))
#define IO_BG2CNT (*(u16*)(MEM_IO + 0x000C))
#define IO_BG3CNT (*(u16*)(MEM_IO + 0x000E))
#define IO_BG0HOFS (*(u16*)(MEM_IO + 0x0010))
#define IO_BG0VOFS (*(u16*)(MEM_IO + 0x0012))
#define IO_BG1HOFS (*(u16*)(MEM_IO + 0x0014))
#define IO_BG1VOFS (*(u16*)(MEM_IO + 0x0016))
#define IO_BG2HOFS (*(u16*)(MEM_IO + 0x0018))
#define IO_BG2VOFS (*(u16*)(MEM_IO + 0x001A))
#define IO_BG3HOFS (*(u16*)(MEM_IO + 0x001C))
#define IO_BG3VOFS (*(u16*)(MEM_IO + 0x001E))

//Key registers.
#define IO_KEYINPUT (*(vu16*)(MEM_IO + 0x0130))
#define IO_KEYCNT (*(u16*)(MEM_IO + 0x0132))

#endif
