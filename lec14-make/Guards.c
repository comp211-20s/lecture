#include <stdio.h>
#include <stdlib.h>

#include "Guards.h"

void* OOM_GUARD(void *p)
{
    if (p == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
