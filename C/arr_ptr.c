// handling 2D array with only one for loop

#include <stdio.h>

#define ROW 3
#define COL 5

int main()
{
    int arr[ROW][COL];

    for (int i = 0; i < ROW * COL; i++)
    {
        arr[i / COL][i % COL] = i;
    }
    for (int i = 0; i < ROW * COL; i++)
    {
        if (i % COL == 0)
            printf("\n");
        printf("%d ", arr[i / COL][i % COL]);
    }

    return 0;
}
