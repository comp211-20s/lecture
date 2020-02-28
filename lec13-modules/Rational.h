#ifndef RATIONAL_H
#define RATIONAL_H

#include <stdint.h>

typedef struct Rational {
    uint64_t numer;
    uint64_t denom;
} Rational;

/**
 * Constructs a new Rational on the heap and returns a pointer to it.
 * Returns NULL when out of memory. Caller must call Rational_free
 * to deallocate the memory.
 */
Rational* Rational_new(int64_t numer, int64_t denom);

/**
 * Allocate a new zero-initialized Rational on the heap. Caller
 * must call Rational_free to deallocate the memory.
 */
Rational* Rational_alloc();

/**
 * Convenience function for initializing the members of a Rational.
 */
void Rational_init(Rational *this, int64_t numer, int64_t denom);

/**
 * Deallocate a Rational. Always returns NULL. Caller is responsible
 * for treating lifetime of any freed Rational as expired and ensuring
 * Rational_free is not called twice on the same Rational*.
 */
Rational* Rational_free(Rational *this);

/**
 * Add two Rational numbers together. Returns a new Rational value.
 */
Rational Rational_add(const Rational *this, const Rational *to);

/**
 * Print a Rational to stdout
 */
void Rational_print(const struct Rational *this);

#endif
