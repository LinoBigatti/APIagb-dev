//Draw an image on mode 5, using 32 bit units. (Recommended)

#ifndef M5_IMAGE_32_H
#define M5_IMAGE_32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <bitmap/mode5/m5_defs.h>

extern void m5_image_32(const void *src_, u32 lenght);

#ifdef __cplusplus
}
#endif

#endif