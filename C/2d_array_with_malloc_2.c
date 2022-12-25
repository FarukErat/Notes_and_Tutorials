#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row = 3, col = 5;
    int *arr = (int *)malloc(row * col * sizeof(int));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i * col + j] = i * col + j;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", arr[i * col + j]);
        }
        printf("\n");
    }

    // another way
    int *arr2 = (int *)malloc(row * col * sizeof(int));

    for (int i = 0; i < row * col; i++)
    {
        arr2[i] = i;
    }

    for (int i = 0; i < row * col; i++)
    {
        if (i % col == 0)
        {
            printf("\n");
        }
        printf("%d\t", arr2[i]);
    }

    return 0;
}
