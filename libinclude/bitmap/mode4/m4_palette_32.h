//Load a palette into mode 4, using 32 bits units. (Recommended)

#ifndef M4_PALETTE_32_H
#define M4_PALETTE_32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode4/m4_defs.h>

extern void m4_palette_32(const void *src_, u32 length);

#ifdef __cplusplus
}
#endif

#endif
