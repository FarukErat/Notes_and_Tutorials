#include <stdio.h>

// x++
int postIncrement(int x)
{
    int temp = x;
    x = x + 1;
    return temp;
}

// ++x
int preIncrement(int x)
{
    x = x + 1;
    return x;
}

int main()
{
    int x = 5;
    printf("x = %d, x++ = %d, ++x = %d", x, postIncrement(x), preIncrement(x));
    // x = 5, x++ = 5, ++x = 6

    return 0;
}