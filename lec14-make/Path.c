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
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = Path_new(next);
    return this->next;
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
    if (this != NULL) {
        Path_free(this->next);
        free(this);
    }
    return NULL;
}

void Path_print(const Path *this)
{
    Path *cursor = (Path *)this; // Cast required to drop const
    while (cursor != NULL) {
        printf("(%f, %f)", cursor->point.x, cursor->point.y);
        cursor = cursor->next;
        if (cursor != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}
