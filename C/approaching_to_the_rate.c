#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, num, rate, repeat, yes = 0, no = 0;

    srand(time(NULL));
    do
    {
        printf("enter a rate: ");
        scanf("%d", &rate);
    } while (rate < 1 || rate > 100);
    
    printf("enter repeat: ");
    scanf("%d", &repeat);

    for (i = 0; i < repeat; i++)
    {
        num = rand() % (100) + 1;
        if (num <= rate)
            yes++;
        else
            no++;
    }
    printf("%f", (float)(yes)*100 / (float)(repeat));
    return 0;
}
