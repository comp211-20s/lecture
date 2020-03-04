#include <stdio.h>

#include "Guards.h"
#include "Path.h"
#include "Point.h"

int main()
{
    Point bottom_left = { 0.0, 0.0 };
    Point bottom_right = { 10.0, 0.0 };
    Point top_center = { 5.0, 5.0 };
    Point points[] = { bottom_left, bottom_right, top_center };
    const size_t length = sizeof(points) / sizeof(Point);

    Path *head = OOM_GUARD(Path_new(points[0]));
    Path *tail = head;
    for (size_t i = 1; i <= length; ++i) {
        tail = Path_extend(tail, points[i % length]);
        OOM_GUARD(tail);
    }

    Path_print(head);
    printf("Length: %f\n", Path_length(head));
    head = Path_free(head);
}
