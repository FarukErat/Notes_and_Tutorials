#include <stdio.h>


int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}

int invoke(int x, int y,
           int (*func)(int, int))
{
    return func(x, y);
}

int main()
{
    int x = 10, y = 20;
    int sum = invoke(x, y, add);
    int product = invoke(x, y, multiply);
    printf("Sum = %d, Product = %d", sum, product);
    return 0;
}
