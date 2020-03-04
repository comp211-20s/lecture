#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "Path.h"
#include "Point.h"

Path* Path_new(Point point)
{
    Path *path = Path_alloc();
    if (path != NULL) {
        Path_init(path, point, NULL);
    }
    return path;
}

Path* Path_alloc()
{
    return calloc(1, sizeof(Path));
}

void Path_init(Path *this, Point point, Path *next)
{
    this->point = point;
    this->next = next;
}

Path* Path_extend(Path *this, Point next)
{
    assert(this != NULL);
    if (this->next == NULL) {
        this->next = Path_new(next);
        return this->next;
    } else {
        return Path_extend(this->next, next);
    }
}

double Path_length(const Path *this)
{
    assert(this != NULL);
    if (this->next == NULL) {
        return 0.0;
    } else {
        double distance = Point_distance(&this->point, &this->next->point);
        return distance + Path_length(this->next);
    }
}

Path* Path_free(Path *this)
{
    free(this);
    return NULL;
}

void Path_print(const Path *this)
{
    if (this != NULL) {
        if (this->next != NULL) {
            printf("(%f, %f) -> ", this->point.x, this->point.y);
            Path_print(this->next);
        } else {
            printf("(%f, %f)\n", this->point.x, this->point.y);
        }
    }
}
