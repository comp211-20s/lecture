#ifndef SLICE_H
#define SLICE_H

#include <stdlib.h>
#include <stdbool.h>

#include "CharItr.h"

typedef struct Slice {
    const char *buffer;
    size_t length;
} Slice;

/* Constructor */

Slice Slice_value(const char *start, size_t length);

/* Accessors */

const char* Slice_start(const Slice *self);

size_t Slice_length(const Slice *self);

/* Methods */

CharItr Slice_get_CharItr(const Slice *self);

#endif
