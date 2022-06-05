#include <stdio.h>
#include <conio.h>

int main()
{
    long long unsigned number;
    int lastDivider;
    int power = 0;
    printf("Enter an integer: ");
    if (scanf("%lld", &number) != 1)
    {
        printf("Invalid input.\n");
        printf("Press any key to exit...");
        getch();
        return 1;
    }

    if (number < 2)
    {
        printf("The number must be equal to or greater than 2.\n");
        printf("Press any key to exit...");
        getch();
        return 1;
    }

    printf("Prime Factors\n");
    printf("-------------\n");
    for (int divider = 2; number != 1; divider++)
    {
        if (number % divider == 0)
        {
            power++;
            number /= divider;
            if (power == 1)
            {
                printf("%d", divider);
            }
            lastDivider = divider;
            --divider;
        }

        if (lastDivider == divider)
        {
            if (power > 1)
            {
                printf(" ^ %d", power);
            }
            printf("\n");
            power = 0;
        }
    }
    if (power > 1)
    {
        printf(" ^ %d", power);
    }
    printf("\n-------------");
    printf("\nPress any key to exit...");
    getch();
    return 0;
}
