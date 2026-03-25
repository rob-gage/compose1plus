// Copyright Rob Gage 2026

#ifndef CONTEXT_H
#define CONTEXT_H

#include "values.h"

typedef struct context_t context_t;

context_t create_context();

/*

value_t pop_value(context_t* context);

void push_value(context_t* context, value_t value);

*/

#endif