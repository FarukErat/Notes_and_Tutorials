#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int element;

    int *array;

    puts("enter the number of elements");
    scanf("%d",&element);

    // malloc returns the number of bytes passed as unsigned integer argument
    // a cast operator is used to get desired type from void pointer type
    array = (int*)malloc(sizeof(int)*element);

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
