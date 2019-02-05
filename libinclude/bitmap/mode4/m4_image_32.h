//Draw an image on mode 4, using 32 bit units. (Recommended)

#ifndef M4_IMAGE_32_H
#define M4_IMAGE_32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode4/m4_defs.h>

extern void m4_image_32(const void *src_, u32 lenght);

#ifdef __cplusplus
}
#endif

#endif