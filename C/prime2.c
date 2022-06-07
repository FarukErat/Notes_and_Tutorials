#include <stdio.h>
#include <conio.h>

int main()
{
    long long int number;
    int divider = 2;
    int lastDivider = 1;
    int power = 0;

    printf("Enter an integer: ");
    if (scanf("%lld", &number) != 1)
    {
        printf("Invalid input.\n");
        printf("Press any key to exit...");
        getch();
        return 1;
    }

    if (number == -1)
    {
        printf("-------------\n");
        printf("-1\n");
        printf("-------------\n");
        printf("Press any key to exit...");
        getch();
        return 0;
    }

    printf("Prime Factors\n");
    printf("-------------");
    if (number < 0)
    {
        number = -number;
        printf("\n-1");
    }
    switch (number)
    {
    case 0:
        printf("\n0");
        break;
    case 1:
        printf("\n1");
        break;
    default:
        while (number != 1)
        {
            if (number % divider == 0)
            {
                number = number / divider;
                if (divider == lastDivider)
                    power++;
                else
                {
                    lastDivider = divider;
                    if (power > 1)
                        printf(" ^ %d", power);
                    printf("\n%d", divider);
                    power = 1;
                }
                if (number == 1)
                {
                    if (power > 1)
                        printf(" ^ %d", power);
                }
            }
            else
                divider++;
        }
        break;
    }
    printf("\n-------------");
    printf("\nPress any key to exit...");
    getch();
    return 0;
}
