#include <stdio.h>
#include <stdlib.h>

struct Point {
    double x;
    double y;
};

// Forward Function Declarations
// Point Point_add(const Point *this, const Point *to);
void Point_print(const struct Point *this);

int main()
{
    // Declare a struct Point variable
    // Print its values
}

void Point_print(const struct Point *this)
{
    printf("(%f, %f)\n", (*this).x, (*this).y);
}
