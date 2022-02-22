#include <stdio.h>

void swap(int*, int*);

int main ()
{
    int m = 10, n = 75;
    printf("before swap: m = %d, n = %d", m, n);
    swap(&m, &n);
    printf("\nafter swap: m = %d, n = %d", m, n);
    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}