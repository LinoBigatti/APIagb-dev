//Basic GBA types for programs.

#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned int vu32;
typedef volatile unsigned long long vu64;

typedef volatile signed char vs8;
typedef volatile signed short vs16;
typedef volatile signed int vs32;
typedef volatile unsigned long long vs64;

typedef const unsigned char cu8;
typedef const unsigned short cu16;
typedef const unsigned int cu32;
typedef const unsigned long long cu64;

typedef const signed char cs8;
typedef const signed short cs16;
typedef const signed int cs32;
typedef const signed long long cs64;

#ifdef __cplusplus
}
#endif

#endif
