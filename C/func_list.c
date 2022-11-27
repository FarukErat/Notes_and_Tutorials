#include <stdio.h>

void first(int num1, int num2)
{
    printf("First function called with %d and %d\n", num1, num2);
}

void second(int num1, int num2)
{
    printf("Second function called with %d and %d\n", num1, num2);
}

void third(int num1, int num2)
{
    printf("Third function called with %d and %d\n", num1, num2);
}

int main()
{
    // create a list to store functions
    void (*funcs[])(int, int) = {first, second, third};
    funcs[1](0, 5); // call second function with 0 and 5
    funcs[0](3, 1); // call first function with 3 and 1
    funcs[2](7, 2); // call third function with 7 and 5

    return 0;
}
