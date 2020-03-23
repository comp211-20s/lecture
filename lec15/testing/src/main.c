#include <stdio.h>
#include <stdlib.h>

#include "copy.h"

int main()
{
    char src[] = "hello, world";
    char dst[sizeof(src)] = { 0 };
    copy(dst, src, sizeof(src));
    printf("src: %s\n", src);
    printf("dst: %s\n", dst);
    return EXIT_SUCCESS;
}
