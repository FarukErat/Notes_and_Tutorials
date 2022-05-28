#include <stdio.h>

float add(int a, int b)
{
    return a + b;
}

float sub(int a, int b)
{
    return a - b;
}

float mul(int a, int b)
{
    return a * b;
}

float div(int a, int b)
{
    return a / b;
}

int main()
{
    float (*calc[])(int, int) = {add, sub, mul, div};
    for (int i = 0; i < 4; i++)
    {
        printf("%.2f\n", calc[i](1, 2));
    }

    return 0;
}
