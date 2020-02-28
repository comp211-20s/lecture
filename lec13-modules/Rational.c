#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "Rational.h"

Rational* Rational_new(int64_t numer, int64_t denom) {
    Rational *value = Rational_alloc();
    if (value != NULL) {
        Rational_init(value, numer, denom);
    }
    return value;
}

Rational* Rational_alloc() {
    return calloc(1, sizeof(Rational));
}

void Rational_init(Rational *this, int64_t numer, int64_t denom) {
    this->numer = numer;
    this->denom = denom;
}

Rational* Rational_free(Rational *this) {
    free(this);
    return NULL;
}

Rational Rational_add(const Rational *this, const Rational *to) {
    uint64_t numer = this->numer * to->denom + to->numer * this->denom;
    uint64_t denom = this->denom * to->denom;
    Rational result = { numer, denom };
    return result;
}

void Rational_print(const struct Rational *this) {
    printf("%lu/%lu\n", this->numer, this->denom);
}
