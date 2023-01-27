#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int calculate(int x, int y,
              int (*func)(int, int))
{
    return func(x, y);
}

int main()
{
    int a = 1, b = 2;
    printf("a + b = %d\n", calculate(a, b, add));
    printf("a - b = %d\n", calculate(a, b, sub));

    return 0;
}