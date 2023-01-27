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

    for (int i = 0; i < row; i++)
    {
        printf("%d -> %d: ", arr + i, *(arr + i));
        for (int j = 0; j < col; j++)
        {
            printf("%d ", *(arr + i) + j);
        }
        printf("\n");
    }
    // output:
    /*
    12260848 -> 12260872: 12260872 12260876 12260880 12260884 12260888
    12260852 -> 12260904: 12260904 12260908 12260912 12260916 12260920
    12260856 -> 12260936: 12260936 12260940 12260944 12260948 12260952
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