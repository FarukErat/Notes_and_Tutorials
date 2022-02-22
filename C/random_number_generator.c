#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    srand (time(NULL));

    int min, maks, num;

    do
    {
        printf("min: ");
        scanf("%d",&min);

        printf("\nmaks: ");
        scanf("%d",&maks);

    }while (min > maks);

    num = rand()%(maks-min+1)+min;

    printf("\nthe number is %d",num);

    return 0;
}