#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row = 3, col = 5;

    // allocate memory for 2d array
    int **arr = (int **)malloc(row * sizeof(int *));

    // allocate memory for each row
    for (int i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
    }

    for (int i = 0; i < row * col; i++)
    {
        arr[i / col][i % col] = i;
    }

    for (int i = 0; i < row * col; i++)
    {
        if (i % col == 0)
        {
            printf("\n");
        }
        printf("%d\t", arr[i / col][i % col]);
    }

    return 0;
}
