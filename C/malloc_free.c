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

    puts("enter the elements");

    for(i = 0; i < element; i++)
    {
        scanf("%d",array + i);
    }

    puts("");

    for(i = 0; i < element; i++)
    {
      printf("%d\n",*(array + i));
    }

    free(array); //it restores memory to the system

    puts("");

    for(i = 0; i < element; i++)
    {
        printf("%d\n",*(array + i));
    }

    return 0;
}