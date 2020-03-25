#include <stdio.h>
#include <stdlib.h>

#include "Vec.h"

int main()
{
    Vec v = Vec_value(2, sizeof(double));

    double x = 1.0;
    for (size_t i = 0; i < 10; ++i) {
        Vec_set(&v, i, &x);
        x *= 2.0;
    }

    for (size_t i = 0; i < Vec_length(&v); ++i) {
        Vec_get(&v, i, &x);
        printf("%f\n", x);
    }

    Vec_drop(&v);
    return EXIT_SUCCESS;
}
