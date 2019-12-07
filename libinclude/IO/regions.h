//Regions of the IO memory.

#ifndef IO_REGIONS_H
#define IO_REGIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/mem_regs.h>
#include <basics/types.h>

//LCD registers.
#define IO_DISPCNT (*(vu16*)(MEM_IO + 0x0000))
#define IO_GREENSWAP (*(vu16*)(MEM_IO + 0x0002))
#define IO_DISPSTAT (*(vu16*)(MEM_IO + 0x0004))
#define IO_VCOUNT (*(vu16*)(MEM_IO + 0x0006))
#define IO_BG0CNT (*(vu16*)(MEM_IO + 0x0008))
#define IO_BG1CNT (*(vu16*)(MEM_IO + 0x000A))
#define IO_BG2CNT (*(vu16*)(MEM_IO + 0x000C))
#define IO_BG3CNT (*(vu16*)(MEM_IO + 0x000E))
#define IO_BG0HOFS (*(vs16*)(MEM_IO + 0x0010))
#define IO_BG0VOFS (*(vs16*)(MEM_IO + 0x0012))
#define IO_BG1HOFS (*(vs16*)(MEM_IO + 0x0014))
#define IO_BG1VOFS (*(vs16*)(MEM_IO + 0x0016))
#define IO_BG2HOFS (*(vs16*)(MEM_IO + 0x0018))
#define IO_BG2VOFS (*(vs16*)(MEM_IO + 0x001A))
#define IO_BG3HOFS (*(vs16*)(MEM_IO + 0x001C))
#define IO_BG3VOFS (*(vs16*)(MEM_IO + 0x001E))
#define IO_BG2PA (*(vs16*)(MEM_IO + 0x0020))
#define IO_BG2PB (*(vs16*)(MEM_IO + 0x0022))
#define IO_BG2PC (*(vs16*)(MEM_IO + 0x0024))
#define IO_BG2PD (*(vs16*)(MEM_IO + 0x0026))
#define IO_BG2X (*(vs32*)(MEM_IO + 0x0028))
#define IO_BG2Y (*(vs32*)(MEM_IO + 0x002C))
#define IO_BG3PA (*(vs16*)(MEM_IO + 0x0030))
#define IO_BG3PB (*(vs16*)(MEM_IO + 0x0032))
#define IO_BG3PC (*(vs16*)(MEM_IO + 0x0034))
#define IO_BG3PD (*(vs16*)(MEM_IO + 0x0036))
#define IO_BG3X (*(vs32*)(MEM_IO + 0x0038))
#define IO_BG3Y (*(vs32*)(MEM_IO + 0x003C))
#define IO_WIN0H (*(vu16*)(MEM_IO + 0x0040))
#define IO_WIN1H (*(vu16*)(MEM_IO + 0x0042))
#define IO_WIN0V (*(v16*)(MEM_IO + 0x0044))
#define IO_WIN1V (*(vu16*)(MEM_IO + 0x0046))
#define IO_WININ (*(vu16*)(MEM_IO + 0x0048))
#define IO_WINOUT (*(vu16*)(MEM_IO + 0x004A))
#define IO_MOSAIC (*(vs32*)(MEM_IO + 0x004C))
#define IO_BLDCNT (*(vu16*)(MEM_IO + 0x0050))
#define IO_BLDALPHA (*(vu16*)(MEM_IO + 0x0052))
#define IO_BLDY (*(vu16*)(MEM_IO + 0x0054))

//Sound registers (based on pin8's naming).
#define IO_SND1SWEEP (*(vu16*)(MEM_IO + 0x0060))
#define IO_SND1CNT (*(vu16*)(MEM_IO + 0x0062))
#define IO_SND1FREQ (*(vu16*)(MEM_IO + 0x0064))
#define IO_SND2CNT (*(vu16*)(MEM_IO + 0x0068))
#define IO_SND2FREQ (*(vu16*)(MEM_IO + 0x006C))
#define IO_SND3SEL (*(vu16*)(MEM_IO + 0x0070))
#define IO_SND3CNT (*(vu16*)(MEM_IO + 0x0072))
#define IO_SND3FREQ (*(vu16*)(MEM_IO + 0x0074))
#define IO_SND4CNT (*(vu16*)(MEM_IO + 0x0078))
#define IO_SND4FREQ (*(vu16*)(MEM_IO + 0x007C))
#define IO_SNDDMGCNT (*(vu16*)(MEM_IO + 0x0080))
#define IO_SNDDSCNT (*(vu16*)(MEM_IO + 0x0082))
#define IO_SNDSTAT (*(vu16*)(MEM_IO + 0x0084))
#define IO_SNDBIAS (*(vu16*)(MEM_IO + 0x0088))
#define IO_SND3RAM0 (*(vu32*)(MEM_IO + 0x0090))
#define IO_SND3RAM1 (*(vu32*)(MEM_IO + 0x0094))
#define IO_SND3RAM2 (*(vu32*)(MEM_IO + 0x0098))
#define IO_SND3RAM3 (*(vu32*)(MEM_IO + 0x009C))
#define IO_SND3RAM IO_SND3RAM0
#define IO_FIFOA (*(vu32*)(MEM_IO + 0x00A0))
#define IO_FIFOB (*(vu32*)(MEM_IO + 0x00A4))

//DMA registers.
#define IO_DMA0SRC (*(vu32*)(MEM_IO + 0x00B0))
#define IO_DMA0DST (*(vu32*)(MEM_IO + 0x00B4))
#define IO_DMA0CNT (*(vu32*)(MEM_IO + 0x00B8))
#define IO_DMA1SRC (*(vu32*)(MEM_IO + 0x00BC))
#define IO_DMA1DST (*(vu32*)(MEM_IO + 0x00C0))
#define IO_DMA1CNT (*(vu32*)(MEM_IO + 0x00C4))
#define IO_DMA2SRC (*(vu32*)(MEM_IO + 0x00C8))
#define IO_DMA2DST (*(vu32*)(MEM_IO + 0x00CC))
#define IO_DMA2CNT (*(vu32*)(MEM_IO + 0x00D0))
#define IO_DMA3SRC (*(vu32*)(MEM_IO + 0x00D4))
#define IO_DMA3DST (*(vu32*)(MEM_IO + 0x00D8))
#define IO_DMA3CNT (*(vu32*)(MEM_IO + 0x00DC))

//Timer registers.
#define IO_TM0DATA (*(vu16*)(MEM_IO + 0x0100))
#define IO_TM0CNT (*(vu16*)(MEM_IO + 0x0102))
#define IO_TM1DATA (*(vu16*)(MEM_IO + 0x0104))
#define IO_TM1CNT (*(vu16*)(MEM_IO + 0x0106))
#define IO_TM2DATA (*(vu16*)(MEM_IO + 0x0108))
#define IO_TM2CNT (*(vu16*)(MEM_IO + 0x010A))
#define IO_TM3DATA (*(vu16*)(MEM_IO + 0x010C))
#define IO_TM3CNT (*(vu16*)(MEM_IO + 0x010E))

//Key registers.
#define IO_KEYINPUT (*(vu16*)(MEM_IO + 0x0130))
#define IO_KEYCNT (*(vu16*)(MEM_IO + 0x0132))

//Interrupt registers.
#define IO_IE (*(vu16*)(MEM_IO + 0x0200))
#define IO_IF (*(vu16*)(MEM_IO + 0x0202))
#define IO_IME (*(vu16*)(MEM_IO + 0x0208))
#define IO_IFBIOS (*(vu16*)(0x03007FF8)) //Bruh
#define IO_ISR (*(fnptr*)(0x03007FFC)) //Bruh

#ifdef __cplusplus
}
#endif

#endif
