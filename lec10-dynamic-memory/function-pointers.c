#include <stdio.h>

void hello();
void world();
int add(int, int);
int sub(int, int);

int main()
{
    static int one = 1;
    int two = 2;
    printf("static &one: %p\n", &one);
    printf("auto   &two: %p\n", &two);
    
}

void hello()
{
    printf("hello\n");
}

void world()
{
    printf("world\n");
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}
