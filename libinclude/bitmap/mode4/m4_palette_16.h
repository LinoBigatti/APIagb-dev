//Load a palette into mode 4, using 16 bits units. (Not recommended)

#ifndef M4_PALETTE_16_H
#define M4_PALETTE_16_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode4/m4_defs.h>

extern void m4_palette_16(const void *src_, u32 length);

#ifdef __cplusplus
}
#endif

#endif
