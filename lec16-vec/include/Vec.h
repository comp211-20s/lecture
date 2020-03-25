#ifndef VEC_H
#define VEC_H

#include <stdlib.h>

/**
 * Vec - a dynamically growable array of any type.
 */

/**
 * The Vec struct is a "thick pointer".
 *
 * Users of Vec should not access these members directly!
 * Instead, use the operations exposed in the functions below.
 */
typedef struct Vec {
    const size_t item_size; /* size of an item in bytes */
    size_t length;          /* number of items in Vec */
    size_t capacity;        /* number of items buffer can store */
    void *buffer;           /* heap memory storing items */
} Vec;

/* Constructor / Destructor */

/**
 * Construct a Vec value. Owner is responsible for calling
 * Vec_drop when its lifetime expires.
 *
 * @param capacity - initial number of items it can store
 * @param item_size - sizeof an individual item
 * @return initialized Vec value.
 */
Vec Vec_value(size_t capacity, size_t item_size);

/**
 * Owner must call to expire a Vec value's lifetime.
 * Frees any heap memory the Vec owns.
 * Resets length, capacity to zero, buffer to NULL.
 */
void Vec_drop(Vec *self);

/* Accessors */

/**
 * Returns the number of items in the Vec.
 */
size_t Vec_length(const Vec *self);

/**
 * Returns a pointer to the items array _for reading only_.
 * You should not write to the returned memory directly!
 */
const void* Vec_items(const Vec *self);

/* Operations */

/**
 * Get a pointer to the item at `index`. You may
 * write to this reference, but not beyond it.
 */
void* Vec_ref(const Vec *self, size_t index);

/**
 * Copy the item at `index` to the memory of `out`.
 */
void Vec_get(const Vec *self, size_t index, void *out);

/**
 * Assign an item at `index` to be a copy of `value`.
 * Valid indices include 0-length. When the index is equal
 * to length, the item is appended to the Vec.
 */
void Vec_set(Vec *self, size_t index, const void *value);

#endif
