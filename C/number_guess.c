#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    srand (time(NULL));

    int min, maks, num, guess, count = 0;

    do
    {
        printf("min: ");
        scanf("%d",&min);

        printf("maks: ");
        scanf("%d",&maks);

    } while (min > maks);

    num = rand()%(maks - min + 1) + min;

    do
    {
        guess = (maks + min)/2;
        printf("\n%d %d %d", min, guess, maks);
        count++;

        if (guess > num)
        {
            maks = guess - 1;
        }

        if (guess < num)
        {
            min = guess + 1;
        }

    } while (guess != num);

    printf("\n\n%d was found on the %d. try", num, count);

    return 0;
}