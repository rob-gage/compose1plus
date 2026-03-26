// Copyright Rob Gage 2026

#include <stddef.h>
#include <stdlib.h>

#include "context.h"
#include "errors.h"
#include "values.h"

context_t create_context() {
    context_t context;
    context.heap_value_buffer = NULL;
    context.heap_value_buffer_capacity = 0;
    context.stack_size = 0;
    return context;
}

value_t pop_value(context_t* context) {
    // produce error if stack is empty
    if (context->stack_size == 0) { return ERROR_TO_VALUE(STACK_UNDERFLOW); }
    // if top of stack is not on heap, return value from inline value buffer
    if (context->stack_size < INLINE_VALUE_COUNT) {
        value_t top = context->inline_value_buffer[context->stack_size - 1];
        context->stack_size--;
        return top;
    }
    value_t top = context->heap_value_buffer[context->stack_size - INLINE_VALUE_COUNT - 1];
    context->stack_size--;
    return top;
}

void push_value(context_t* context, value_t value) {
    // store the value in the inline value buffer if it has available space
    if (context->stack_size < INLINE_VALUE_COUNT) {
        context->inline_value_buffer[context->stack_size] = value;
        context->stack_size++;
        return;
    }
    // reallocate the heap value buffer if necessary
    if (context->heap_value_buffer_capacity <= context->stack_size - INLINE_VALUE_COUNT) {
        size_t new_capacity = context->heap_value_buffer_capacity * 2;
        if (new_capacity == 0) { new_capacity = INLINE_VALUE_COUNT; }
        value_t* new_buffer = realloc(context->heap_value_buffer, new_capacity * sizeof(value_t));
        if (!new_buffer) { abort(); }
        context->heap_value_buffer = new_buffer;
        context->heap_value_buffer_capacity = new_capacity;
    }
    // push the value to the heap value buffer
    context->heap_value_buffer[context->stack_size - INLINE_VALUE_COUNT] = value;
    context->stack_size++;
    return;
}