#ifndef POINT_H
#define POINT_H

typedef struct Point {
    double x;
    double y;
} Point;

/**
 * Constructs a new Point on the heap and returns a pointer to it.
 * Returns NULL when out of memory. Caller must call Point_free
 * to deallocate the memory.
 */
Point* Point_new(double x, double y);

/**
 * Allocate a new zero-initialized Point on the heap. Caller
 * must call Point_free to deallocate the memory.
 */
Point* Point_alloc();

/**
 * Convenience function for initializing the members of a Point.
 */
void Point_init(Point *this, double x, double y);

/**
 * Compute the cartesian distance between two Points.
 */
double Point_distance(const Point *this, const Point *other);

/**
 * Deallocate a Point. Always returns NULL. Caller is responsible
 * for treating lifetime of any freed Point as expired and ensuring
 * Point_free is not called twice on the same Point*.
 */
Point* Point_free(Point *this);

/**
 * Print a Point to stdout
 */
void Point_print(const struct Point *this);

#endif
