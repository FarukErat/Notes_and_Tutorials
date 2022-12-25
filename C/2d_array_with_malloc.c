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

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = i * col + j;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    /*
    output:

    0       1       2       3       4
    5       6       7       8       9
    10      11      12      13      14
    */

    return 0;
}
