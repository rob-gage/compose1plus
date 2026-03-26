// Copyright Rob Gage 2026

#ifndef BOOLEANS_H
#define BOOLEANS_H

#include "values.h"

typedef char boolean_t;

#define FALSE ((boolean_t)0)

#define TRUE ((boolean_t)1)

#define BOOLEAN_FROM_VALUE(value) \
    ((boolean_t)(VALUE_TO_INTEGER(value) != 0))

#define BOOLEAN_TO_VALUE(value) \
    VALUE_FROM_INTEGER(BOOLEAN, (int64_t)(value))

#endif