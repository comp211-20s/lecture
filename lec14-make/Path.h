#ifndef PATH_H
#define PATH_H

#include <stdint.h>
#include "Point.h"

typedef struct Path {
    Point point;
    struct Path *next;
} Path;

/**
 * Constructs a new Path on the heap and returns a pointer to it.
 * Path's next member will point to NULL. Caller responsible for
 * calling Path_free on returned pointer to expire lifetime.
 */
Path* Path_new(Point from);

/**
 * Allocate a new zero-initialized Path on the heap. Caller
 * must call Path_free to deallocate the memory.
 */
Path* Path_alloc();

/**
 * Convenience function for initializing the members of a Path.
 */
void Path_init(Path *this, Point from, Path *next);

/**
 * Extend a Path by creating a new Path Node at its tail. 
 * Returns a pointer to the next Path for future extensions. 
 * The returned Pointer is considered owned by the head Path 
 * in the list and MUST NOT be freed manually.
 *
 * Will return NULL if heap is out of memory.
 */
Path* Path_extend(Path *this, Point next);

/**
 * Compute the total length of a Path.
 */
double Path_length(const Path *this);

/**
 * Deallocate a Path. Always returns NULL. Caller is responsible
 * for treating lifetime of any freed Path as expired and ensuring
 * Path_free is not called twice on the same Path. Frees all owned
 * Paths linked to via next.
 */
Path* Path_free(Path *this);

/**
 * Print a Path to stdout
 */
void Path_print(const struct Path *this);

#endif
