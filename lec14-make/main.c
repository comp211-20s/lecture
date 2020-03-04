#include <stdio.h>

#include "Guards.h"
#include "Path.h"
#include "Point.h"

int main()
{
    Point bottom_left = { 0.0, 0.0 };
    Point bottom_right = { 10.0, 0.0 };
    Point top_right = { 10.0, 10.0 };
    Point top_left = { 10.0, 0.0 };

    Point points[] = { bottom_left, bottom_right, top_right, top_left };
    const size_t length = sizeof(points) / sizeof(Point);

    Path *head = OOM_GUARD(Path_new(points[0]));
    Path *tail = head;

    tail = Path_extend(tail, points[1]);
    OOM_GUARD(tail);

    tail = Path_extend(tail, points[2]);
    OOM_GUARD(tail);

    tail = Path_extend(tail, points[3]);
    OOM_GUARD(tail);

    tail = Path_extend(tail, points[0]);
    OOM_GUARD(tail);

    Path_print(head);
    printf("Length: %f\n", Path_length(head));
    head = Path_free(head);

    head = OOM_GUARD(Path_new(points[0]));
    tail = head;
    for (size_t i = 1; i <= length; ++i) {
        tail = Path_extend(tail, points[i % length]);
        OOM_GUARD(tail);
    }
    Path_print(head);
    printf("Length: %f\n", Path_length(head));
    head = Path_free(head);
}
