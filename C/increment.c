#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;

    // int temp = i; i = i + 1; return temp;
    printf("%d\n", i++); // 0

    // j = j + 1; return j;
    printf("%d\n", ++j); // 1

    return 0;
}
