#ifndef GUARDS_H
#define GUARDS_H

/**
 * OOM_GUARD is intended for use with malloc/calloc/realloc. It takes in
 * a pointer and exits the program with an "out of memory" message if
 * the pointer is null. Otherwise it return the same pointer back to the
 * callee.
 */
void* OOM_GUARD(void *p);

#endif
