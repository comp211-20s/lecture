#include "Slice.h"

Slice Slice_value(const char *start, size_t length)
{
    Slice s = {
        start,
        length
    };
    return s;
}

const char* Slice_start(const Slice *self)
{
    return self->buffer;
}

size_t Slice_length(const Slice *self)
{
    return self->length;
}

CharItr Slice_get_CharItr(const Slice *self)
{
    return CharItr_value(self->buffer, self->length);
}
