#include <stdio.h>

#define maks(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int main()
{
    int x, y;

    printf("enter two numbers\n");

    scanf("%d%d", &x, &y);

    printf("\n%d>%d", maks(x, y), min(x, y));

    return 0;
}