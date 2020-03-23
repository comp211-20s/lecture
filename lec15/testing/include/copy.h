#ifndef COPY_H
#define COPY_H

#include <stdlib.h>

/**
 * Copy a block of memory
 *
 * Copies the values of num bytes from the location pointed to 
 * by * source directly to the memory block pointed to by 
 * destination.
 * 
 * The underlying type of the objects pointed to by both the 
 * source * and destination pointers are irrelevant for this 
 * function; The result is a binary copy of the data.
 * 
 * The function does not check for any terminating null 
 * character in source - it always copies exactly num bytes.
 * 
 * To avoid overflows, the size of the arrays pointed to by
 * both the destination and source parameters, shall be at 
 * least num bytes, and should not overlap.
 *
 * Returns destination.
 */
void* copy(void *destination, const void *source, size_t num);

#endif
