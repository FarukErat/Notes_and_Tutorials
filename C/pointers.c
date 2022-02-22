#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
    int num = 100;

    int array[5];

    int *reference;
    int *ptrArray;

    reference = &num; //& sign points to the memory address of the variable called num

    int num2 = *reference; //* sign shows the number saved on the memory address called reference

    *reference = 150;

    printf("num = %d\n",num);
    printf("num2 = %d",num2);

    printf("\n\nenter five numbers\n");

    for(i = 0; i < 5; i++)
    	scanf("%d",&array[i]);

    for(i = 0; i < 5; i++)
    	printf("\n%d",array[i]);

    ptrArray = (int*)malloc(sizeof(int) * 5);

    printf("\n\nenter another five numbers\n");

    for(i = 0; i < 5; i++)
    	scanf("%d",&ptrArray[i]);

    for(i = 0; i < 5; i++)
    	printf("\n%d",ptrArray[i]);

    printf("\n\nenter another five numbers\n");

    for(i = 0; i < 5; i++)
    	scanf("%d",ptrArray + i);

    for(i = 0; i < 5; i++)
    	printf("\n%d",*(ptrArray + i));

    free(ptrArray);

  return 0;
}