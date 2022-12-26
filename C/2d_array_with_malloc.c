#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row = 3, col = 5;
    int **arr;

    // allocate memory for rows
    arr = (int **)malloc(row * sizeof(int *));

    // allocate memory for columns
    for (int i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
    }

    // print addresses
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", &arr[i][j]);
        }
        printf("\n");
    }
    // output:
    /*
    11802120        11802124        11802128        11802132        11802136
    11802152        11802156        11802160        11802164        11802168
    11802184        11802188        11802192        11802196        11802200
    */

    // assign values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = i * col + j;
        }
    }

    // access values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    // output:
    /*
    0       1       2       3       4
    5       6       7       8       9
    10      11      12      13      14
    */

    // deallocate memory
    for (int i = 0; i < row; i++)
    {
        free(arr[i]);
    }
    free(arr);


    return 0;
}
