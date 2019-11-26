//Do a silence.

#ifndef SILENCE_H
#define SILENCE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <basics/types.h>
#include <basics/bios.h>
#include <basics/vsync.h>
#include <IO.h>

void silence(u32 length);

#ifdef __cplusplus
}
#endif

#endif