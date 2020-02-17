#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_LEN 26

/**
 * This program's purpose is to demonstrate fundamental operations
 * around dynamic memory w/ malloc, caloc, realloc, and free.
 */

char *new_string(size_t);
void fill_lowercase(char[]);
char *resize_string(char*, size_t);

int main()
{
    char *str = new_string(ALPHABET_LEN + 1);
    fill_lowercase(str);
    printf("%s\n", str);
}

/**
 * Allocates a character array on the heap of size_t and zeros
 * the memory out. Program exits if out of memory.
 */
char *new_string(size_t size)
{
    return NULL;
}

/**
 * Resize char array to be of `size` bytes and return pointer
 * to (potentially) new location of char array. If moved,
 * all bytes copied automatically. Program exits if out of mem.
 */
char *resize_string(char *str, size_t size)
{
    return NULL;
}

/**
 * Given the pointer to an array of characters, fill it with 
 * all lowercase letters. Caller must ensure length is at least
 * 27 chars.
 */
void fill_lowercase(char str[])
{
    for (int i = 0; i <= ALPHABET_LEN; ++i) {
        str[i] = 'a' + i;
    }
    str[ALPHABET_LEN] = '\0';
}

