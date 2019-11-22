#ifndef BIOS_H
#define BIOS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <background/bg_defs.h>
#include <object/obj_defs.h>

//Structs for various BIOS functions.

typedef struct BitUnPackData {
    u16 srcLen;
    u8 srcBpp;
    u8 dstBpp;
    u32 dst;
} BupData;

typedef	struct { //This one was copied from TONC because I have no idea how it works lmao.
	u32	reserved1[5];
	u8	handshake_data;
	u8	padding;
	u16	handshake_timeout;
	u8	probe_count;
	u8	client_data[3];
	u8	palette_data;
	u8	response_bit;
	u8	client_bit;
	u8	reserved2;
	u8	*boot_srcp;
	u8	*boot_endp;
	u8	*masterp;
	u8	*reserved3[3];
	u32	system_work2[4];
	u8	sendflag;
	u8	probe_target_bit;
	u8	check_wait;
	u8	server_type;
} MultiBootParam;

void SoftReset(void); //Swi 0x00

void RegisterRamReset(u32 flags); //Swi 0x01

void Halt(void); //Swi 0x02

void Stop(void); //Swi 0x03

void IntrWait(u32 keepOld, u32 IRQ); //Swi 0x04

void VBlankIntrWait(void); //Swi 0x05

s32 Div(s32 num, s32 denom); //Swi 0x06

s32 DivArm(s32 denom, s32 num); //Swi 0x07

u32 Sqrt(u32 num); //Swi 0x08

s16 ArcTan(s16 theta); //Swi 0x09

s16 ArcTan2(s16 x, s16 y); //Swi 0x0A

void CpuSet(const void *src, void *dst, u32 mode); //Swi 0x0B

void CpuFastSet(const void *src, void *dst, u32 mode); //Swi 0x0C

u32 BiosCheckSum(void); //Swi 0x0D

void BgAffineSet(const bg_affine_src *src, bg_affine *dst, s32 num);

void ObjAffineSet(const obj_affine_src *src, void *dst, s32 num, s32 offset);

void BitUnPack(const void *src, void *dst, const BupData Bup); //Swi 0x10

void LZ77UnCompWRAM(const void *src, void *dst); //Swi 0x11

void LZ77UnCompVRAM(const void *src, void *dst); //Swi 0x12

void HuffUnComp(const void *src, void *dst); //Swi 0x13

void RLUnCompWRAM(const void *src, void *dst); //Swi 0x14

void RLUnCompVRAM(const void *src, void *dst); //Swi 0x15

void Diff8bitUnFilterWRAM(const void *src, void *dst); //Swi 0x16

void Diff8bitUnFilterVRAM(const void *src, void *dst); //Swi 0x17

void Diff16bitUnFilter(const void *src, void *dst); //Swi 0x18

void SoundBias(u16 bias); //Swi 0x19

void SoundDriverInit(void *src); //Swi 0x1A

void SoundDriverMode(u32 mode); //Swi 0x1B

void SoundDriverMain(void); //Swi 0x1C

void SoundDriverVSync(void); //Swi 0x1D

void SoundChannelClear(void); //Swi 0x1E

//MidiKeyToFreq (Undocumented)

//MusicPlayerOpen (Undocumented)

//MusicPlayerStart (Undocumented)

//MusicPlayerStop (Undocumented)

//MusicPlayerContinue (Undocumented)

//MusicPlayerFadeOut (Undocumented)

int MultiBoot(MultiBootParam* mb, u32 mode);

void HardReset(void); //Swi 0x26

void CustomHalt(int filler, u32 params); //Swi 0x27 (Undocumented)

void SoundDriverVSyncOff(void); //Swi 0x28

void SoundDriverVSyncOn(void); //Swi 0x29

#ifdef __cplusplus
}
#endif

#endif