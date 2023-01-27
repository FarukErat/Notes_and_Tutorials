#include <stdio.h>

#define ROW 2
#define COL 3

int main()
{
    printf("-----\n");
    // 1D array
    // using index operator
    int a[COL];
    for (int i = 0; i < COL; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < COL; i++)
    {
        printf("%d ", i, a[i]);
    }
    printf("\n-----\n");

    // using pointer arithmetic
    for (int i = 0; i < COL; i++)
    {
        *(a + i) = i;
    }
    for (int i = 0; i < COL; i++)
    {
        printf("%d ", i, *(a + i));
    }
    printf("\n-----\n");

    // 2D array
    // using index operator
    int b[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            b[i][j] = i * COL + j;
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("-----\n");

    // using pointer arithmetic
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            *(*(b + i) + j) = i * COL + j;
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d ", *(*(b + i) + j));
        }
        printf("\n");
    }
    printf("-----\n");

    return 0;
}
