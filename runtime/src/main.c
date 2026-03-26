// Copyright Rob Gage 2026

#include <stdio.h>

#include "booleans.h"
#include "context.h"
#include "values.h"

int main() {
    context_t context = create_context();
    push_value(&context, BOOLEAN_TO_VALUE(TRUE));
    value_t popped_value = pop_value(&context);
    if (popped_value == BOOLEAN_TO_VALUE(TRUE)) {
        printf("popped_value is true\n");
    }
    printf("Compose\n");
    return 0;
}