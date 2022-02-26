#include <stdio.h>

#define ROW 3
#define COL 5

int main()
{
    int arr[ROW][COL];
    int *ptr = &arr[0][0];

    // fill the array
    for (int i = 0; i < ROW * COL; i++)
    {
        *(ptr + i) = i;
    }
    // print the array
    for (int i = 0; i < ROW * COL; i++)
    {
        printf("%d ", *(ptr + i));
    }

    return 0;
}
