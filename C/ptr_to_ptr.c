#include <stdio.h>
#include <stdlib.h>

void printMatris(int **, int, int);

int main()
{
	int i, j;
	int x, y;

	int **matris;

	printf("enter the number of the columns: ");
	scanf("%d",&x);

	printf("\nenter the number of the lines: ");
	scanf("%d",&y);

	matris = (int **)malloc(sizeof(int*) * y);

	for(i = 0; i < y; i++)
	{
		matris[i] = (int *)malloc(sizeof(int) * x);
	}

	printf("\nenter the numbers\n");

	for(i = 0; i < y; i++)
	{
	    for(j = 0; j < x; j++)
	    {
	    	printf("matris[%d][%d] = ", i, j);
	    	scanf("%d",&(matris[i][j]));
		}
	}

	printMatris(matris, x, y);

	free(matris);

    return 0;
}

void printMatris(int** matris, int x, int y)
{
	int i, j;

	puts("\nthe numbers\n");

	for(i = 0; i < y; i++)
	{
		for(j = 0; j < x; j++)
	    {
	    	printf("matris[%d][%d] = %d\n", i, j, matris[i][j]);
		}
	}
}