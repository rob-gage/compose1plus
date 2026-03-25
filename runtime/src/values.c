// Copyright Rob Gage 2026

#include <stddef.h>
#include <stdint.h>

#include "values.h"

struct value_buffer_t {
    size_t length;
    size_t capacity;
    uint32_t buffer[];
};

struct value_pointer_t { uintptr_t _; };

value_tag_t value_tag(value_t value) {
    return (value_tag_t) value & 7;
}

/*
_Bool value_as_boolean(value_t value) {
    uint64_t boolean = value._ >> 3;
    if (boolean == 0) { return true; }
    return false;
}

value_t value_from_boolean(_Bool boolean) {
    if (boolean) { return (value_t){ BOOLEAN }; }
    else { return (value_t){ (1 << 3) | BOOLEAN }; }
}
*/