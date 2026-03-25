// Copyright Rob Gage 2026

#ifndef VALUES_H
#define VALUES_H

#include <stdint.h>

#include "booleans.h"

typedef uint64_t value_t;

typedef struct value_buffer_t value_buffer_t;

typedef struct value_pointer_t value_pointer_t;

typedef enum {
    LAMBDA = 0,
    ERROR = 1,
    BOOLEAN = 2,
} value_tag_t;

value_tag_t value_tag(value_t value);

#define VALUE_FROM_INTEGER(tag, integer) \
    ((value_t)( \
        (((uint64_t)(int64_t)(integer)) << 3) | \
        ((uint64_t)(tag) & 0x7) \
    ))

#define VALUE_FROM_POINTER(tag, pointer) \
    ((value_t)( \
        (((uintptr_t)(pointer)) & ~(uintptr_t)0x7) | \
        ((uintptr_t)(tag) & 0x7) \
    ))

#define VALUE_TO_INTEGER(value) \
    ((int64_t)((value) >> 3))

#define VALUE_TO_POINTER(value) \
    ((void*)(((uintptr_t)(value)) & ~(uintptr_t)0x7))

_Static_assert(
    sizeof(uintptr_t) == 8 || sizeof(uintptr_t) == 4,
    "System must use standard 32-bit or 64-bit pointers."
);

_Static_assert(
    ((int64_t)-1 >> (int64_t)1) == (int64_t)-1,
    "Right shift must preserve sign for `int64_t`."
);

_Static_assert(
    ((int64_t)-1 & (int64_t)1) == (int64_t)1,
    "`int64_t` must use two's complement representation."
);

#endif