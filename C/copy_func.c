#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main()
{
    int (*a)(int, int) = add;
    printf("%d\n", a(1, 2)); // 3
    a = sub;
    printf("%d\n", a(1, 2)); // -1

    return 0;
}
