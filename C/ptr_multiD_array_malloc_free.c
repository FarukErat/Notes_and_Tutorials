#include <stdio.h>
//#include <stdlib.h>

#define ROW 3
#define COL 5

void fillArray(int *);
void printArray(int *);

int main()
{
    int arr[ROW][COL];
    // int *arr = (int*)malloc(ROW * COL * sizeof(int));

    int *ptr = &arr[0][0]; // delete this line and name ptr to arr
    fillArray(ptr);
    printArray(ptr);

    // free(arr);

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
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            printf("%d\t", *(ptr + COL * row + col));
        }
        printf("\n");
    }
}