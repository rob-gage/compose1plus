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

void k_drop(context_t* context) {
    value_t value = pop_value(context);
    if (IS_ERROR(value)) { push_value(context, value); }
    return;
}

void k_hop(context_t* context) {
    value_t value_b = pop_value(context);
    if (IS_ERROR(value_b)) {
        push_value(context, value_b);
        return;
    }
    value_t value_a = pop_value(context);
    if (IS_ERROR(value_a)) {
        push_value(context, value_b);
        push_value(context, value_a);
        return;
    }
    push_value(context, value_a);
    push_value(context, value_b);
    push_value(context, value_a);
}