// Copyright Rob Gage 2026

#ifndef CONTEXT_H
#define CONTEXT_H

#include <stddef.h>

#include "values.h"

#define INLINE_VALUE_COUNT 1024

typedef struct {
    // data stack
    value_t inline_value_buffer[INLINE_VALUE_COUNT];
    value_t* heap_value_buffer;
    size_t heap_value_buffer_capacity;
    size_t stack_size;
} context_t;

context_t create_context();

value_t pop_value(context_t* context);

void push_value(context_t* context, value_t value);

#endif