#include <stdio.h>

#define ROW 3
#define COL 5

void fillArray(int arr[3][5]);
void printArray(int arr[3][5]);

int main()
{
    int arr[ROW][COL];

    fillArray(arr);
    printArray(arr);

    return 0;
}

void fillArray(int arr[3][5])
{
    int count = 0;

    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            *(*(arr + row) + col) = count;
            count++;
        }
    }
}

void printArray(int arr[3][5])
{
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            printf("%d ", arr);				// the pointer of the array
            printf("%d ", arr + row);			// the same as *(arr + row)
            printf("%d ", *(arr + row));		// the pointer of the rows
            printf("%d ", *(arr + row) + col);		// the same as *(*(arr + row) + col)
            printf("%d\n", *(*(arr + row) + col));	// the pointer of the pointer of rows
        }
        printf("\n");
    }
}