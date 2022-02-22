#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i, j;
	int element;
	int temp;
    
    int *array;
    
    printf("input element number: ");

    scanf("%d",&element);

    array = (int*)malloc(sizeof(int)*element);

    printf("\ninput numbers\n");

    for (i = 0; i < element; i++)
    {
        scanf("%d",array + i);
    }

    for (i = 0; i < element-1; i++)
    {
        for(j = 0; j < element-1-i; j++)
        {
            if (*(array + j) > *(array + j + 1))
            {
                temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }

    printf("\nthe numbers in ascending order\n");

    for (i = 0; i < element; i++)
    {
        printf("%d\n",*(array + i));
    }

    return 0;
}