#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Point.h"

Point* Point_new(double x, double y)
{
    Point *p = Point_alloc();
    if (p != NULL) {
        Point_init(p, x, y);
    }
    return p;
}

Point* Point_alloc()
{
    return calloc(1, sizeof(Point));
}

void Point_init(Point *this, double x, double y)
{
    this->x = x;
    this->y = y;
}

double Point_distance(const Point *this, const Point *other)
{
    double xDelta2 = pow(other->x - this->x, 2);
    double yDelta2 = pow(other->y - this->y, 2);
    return sqrt(xDelta2 + yDelta2);
}

Point* Point_free(Point *this)
{
    free(this);
    return NULL;
}

void Point_print(const struct Point *this)
{
    printf("(%f, %f)\n", this->x, this->y);
}
