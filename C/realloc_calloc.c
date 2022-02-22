#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int element;

    int *array;

    puts("enter the number of elements");
    scanf("%d",&element);

    array = (int*)malloc(sizeof(int)*element); //it gives the pointer a free memory address

    printf("\nthe numbers in the array before declaration\n");

    for(i = 0; i < element; i++)
    {
      printf("%d\n",*(array + i));
    }
    
    puts("\nenter the elements");
  
    for(i = 0; i < element; i++)
    {
        scanf("%d",array + i);
    }

    printf("\nthe number after declaration\n");

    for(i = 0; i < element; i++)
    {
        printf("%d\n",*(array + i));
    }

    element += 5;
    array = (int*)realloc(array, sizeof(int)*element);

    printf("\nthe numbers after realloc element+5\n");

    for(i = 0; i < element; i++)
    {
        printf("%d\n",*(array + i));
    }

    array = (int*)calloc(element, sizeof(int));

    printf("\nthe numbers after calloc\n");

    for(i = 0; i < element; i++)
    {
        printf("%d\n",*(array + i));
    }

    free(array); //it restores memory to the system

    printf("\nthe numbers after free()\n");

    for(i = 0; i < element; i++)
    {
        printf("%d\n",*(array + i));
    }

    return 0;
}