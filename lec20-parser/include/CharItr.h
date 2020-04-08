#ifndef CHAR_ITR_H
#define CHAR_ITR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct CharItr {
    const char *cursor;
    const char *sentinel;
} CharItr;

/*
 * Constructor. Resulting CharItr value does not own any
 * heap memory thus there is no drop function. Resulting
 * value's lifetime is dependent upon the start reference.
 */
CharItr CharItr_value(const char *start, size_t length);

/*
 * Returns a pointer to the current location of the iterator's cursor.
 */
const char* CharItr_cursor(const CharItr *self);

/*
 * Returns true when there are additional characters to consume
 * in the iterable range.
 */
bool CharItr_has_next(const CharItr *self);

/*
 * Peek and return the next character. Do not advance cursor.
 * Will crash with out of bounds error if no more characters
 * to consume.
 */
char CharItr_peek(const CharItr *self);

/*
 * Read next character and advances cursor.
 * Will crash with out of bounds error if no more characters
 * to consume.
 */
char CharItr_next(CharItr *self);

#endif
