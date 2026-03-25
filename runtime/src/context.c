// Copyright Rob Gage 2026

#include <stddef.h>

#include "context.h"
#include "values.h"

#define INLINE_VALUE_BUFFER_SIZE 1024

struct context_t {
    value_t inline_stack[INLINE_VALUE_BUFFER_SIZE];
    value_t* stack;
    size_t stack_size;
    size_t stack_capacity;
};

context_t create_context() {
    context_t context;
    context.stack = context.inline_stack;
    context.stack_size = 0;
    context.stack_capacity = INLINE_VALUE_BUFFER_SIZE;
    return context;
}

/*

value_t pop_value(context_t* context) {
    // TODO
}

void push_value(context_t* context, value_t value) {
    // TODO
}
*/