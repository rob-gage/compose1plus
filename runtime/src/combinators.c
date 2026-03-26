// Copyright Rob Gage 2026

#include "context.h"
#include "values.h"

// stack combinators

void k_copy(context_t* context) {
    value_t value = pop_value(context);
    push_value(context, value);
    if (IS_ERROR(value)) { return; }
    push_value(context, value);
    return;
}