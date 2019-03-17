//Regions of the IO memory.

#ifndef IO_REGIONS_H
#define IO_REGIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/mem_regs.h>
#include <basics/types.h>

//LCD registers.
#define IO_DISPCNT (*(u16*)(MEM_IO + 0x0000))
#define IO_GREENSWAP (*(u16*)(MEM_IO + 0x0002))
#define IO_DISPSTAT (*(vu16*)(MEM_IO + 0x0004))
#define IO_VCOUNT (*(vu16*)(MEM_IO + 0x0006))
#define IO_BG0CNT (*(u16*)(MEM_IO + 0x0008))
#define IO_BG1CNT (*(u16*)(MEM_IO + 0x000A))
#define IO_BG2CNT (*(u16*)(MEM_IO + 0x000C))
#define IO_BG3CNT (*(u16*)(MEM_IO + 0x000E))
#define IO_BG0HOFS (*(s16*)(MEM_IO + 0x0010))
#define IO_BG0VOFS (*(s16*)(MEM_IO + 0x0012))
#define IO_BG1HOFS (*(s16*)(MEM_IO + 0x0014))
#define IO_BG1VOFS (*(s16*)(MEM_IO + 0x0016))
#define IO_BG2HOFS (*(s16*)(MEM_IO + 0x0018))
#define IO_BG2VOFS (*(s16*)(MEM_IO + 0x001A))
#define IO_BG3HOFS (*(s16*)(MEM_IO + 0x001C))
#define IO_BG3VOFS (*(s16*)(MEM_IO + 0x001E))
#define IO_BG2PA (*(s16*)(MEM_IO + 0x0020))
#define IO_BG2PB (*(s16*)(MEM_IO + 0x0022))
#define IO_BG2PC (*(s16*)(MEM_IO + 0x0024))
#define IO_BG2PD (*(s16*)(MEM_IO + 0x0026))
#define IO_BG2X (*(s32*)(MEM_IO + 0x0028))
#define IO_BG2Y (*(s32*)(MEM_IO + 0x002C))
#define IO_BG3PA (*(s16*)(MEM_IO + 0x0030))
#define IO_BG3PB (*(s16*)(MEM_IO + 0x0032))
#define IO_BG3PC (*(s16*)(MEM_IO + 0x0034))
#define IO_BG3PD (*(s16*)(MEM_IO + 0x0036))
#define IO_BG3X (*(s32*)(MEM_IO + 0x0038))
#define IO_BG3Y (*(s32*)(MEM_IO + 0x003C))
#define IO_WIN0H (*(u16*)(MEM_IO + 0x0040))
#define IO_WIN1H (*(u16*)(MEM_IO + 0x0042))
#define IO_WIN0V (*(u16*)(MEM_IO + 0x0044))
#define IO_WIN1V (*(u16*)(MEM_IO + 0x0046))
#define IO_WININ (*(u16*)(MEM_IO + 0x0048))
#define IO_WINOUT (*(u16*)(MEM_IO + 0x004A))
#define IO_MOSAIC (*(s32*)(MEM_IO + 0x004C))
#define IO_BLDCNT (*(u16*)(MEM_IO + 0x0050))
#define IO_BLDALPHA (*(u16*)(MEM_IO + 0x0052))
#define IO_BLDY (*(u16*)(MEM_IO + 0x0054))

//DMA registers.
#define IO_DMA0SRC (*(u32*)(MEM_IO + 0x00B0))
#define IO_DMA0DST (*(u32*)(MEM_IO + 0x00B4))
#define IO_DMA0CNT (*(u32*)(MEM_IO + 0x00B8))
#define IO_DMA1SRC (*(u32*)(MEM_IO + 0x00BC))
#define IO_DMA1DST (*(u32*)(MEM_IO + 0x00C0))
#define IO_DMA1CNT (*(u32*)(MEM_IO + 0x00C4))
#define IO_DMA2SRC (*(u32*)(MEM_IO + 0x00C8))
#define IO_DMA2DST (*(u32*)(MEM_IO + 0x00CC))
#define IO_DMA2CNT (*(u32*)(MEM_IO + 0x00D0))
#define IO_DMA3SRC (*(u32*)(MEM_IO + 0x00D4))
#define IO_DMA3DST (*(u32*)(MEM_IO + 0x00D8))
#define IO_DMA3CNT (*(u32*)(MEM_IO + 0x00DC))

//Key registers.
#define IO_KEYINPUT (*(vu16*)(MEM_IO + 0x0130))
#define IO_KEYCNT (*(u16*)(MEM_IO + 0x0132))

#ifdef __cplusplus
}
#endif

#endif
