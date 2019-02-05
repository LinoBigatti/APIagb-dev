//Draw an image on mode 3, using 32 bit units. (Recommended)

#ifndef M3_IMAGE_32_H
#define M3_IMAGE_32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode3/m3_defs.h>

extern void m3_image_32(const void *src_, u32 lenght);

#ifdef __cplusplus
}
#endif

#endif