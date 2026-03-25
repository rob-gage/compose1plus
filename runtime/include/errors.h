// Copyright Rob Gage 2026

#ifndef ERRORS_H
#define ERRORS_H

typedef enum {
	STACK_UNDERFLOW = 0,
} error_t;

#define ERROR_FROM_VALUE(value) \
	((error_t)VALUE_TO_INTEGER(value))

#define ERROR_TO_VALUE(error) \
	VALUE_FROM_INTEGER(ERROR, (int64_t)(error))

#endif