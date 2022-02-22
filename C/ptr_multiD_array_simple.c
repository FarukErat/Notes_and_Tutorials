#include <stdio.h>

#define ROW 3
#define COL 5

void fillArray(int *);
void printArray(int *);

int main()
{
    int arr[ROW][COL];

    int *ptr = &arr[0][0];
    fillArray(ptr);
    printArray(ptr);

    return 0;
}

void fillArray(int *ptr)
{
    int count = 0;

    for (int i = 0; i < ROW * COL; i++)
    {
        *(ptr + i) = count;
        count++;
    }
}

void printArray(int *ptr)
{
    for (int i = 0; i < ROW * COL; i++)
    {
        printf("%d\n", *(ptr + i));
    }
}