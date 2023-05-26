/*
 * Class for defining the normal types as a shorter name,
 * ex: uint8_t -> int8
 */

#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

// All of this are unsigned
typedef uint8_t  int8; // This can be also expressed as "char" which is a 1 byte integer
typedef uint16_t int16;
typedef uint32_t int32;
typedef uint64_t int64;

#endif // TYPES_H