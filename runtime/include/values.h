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

/*
_Bool value_as_boolean(value_t value) {
    uint64_t boolean = value._ >> 3;
    if (boolean == 0) { return true; } else { return false; }
}

value_t value_from_boolean(_Bool boolean);
*/
#endif