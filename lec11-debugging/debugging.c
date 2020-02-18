#include <stdio.h>
#include <stdlib.h>

static char *HELLO = "hello";

size_t length(char *);
void copy(char *, char *);

int main()
{
    size_t len = length(HELLO);
    char *clone = calloc(len, sizeof(char));
    copy(HELLO, clone);
    printf("%s\n", clone);
}

size_t length(char *str)
{
    size_t result = 0;
    while (*str != '\0') {
        result++;
        str++;
    }
    return result;
}

void copy(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
