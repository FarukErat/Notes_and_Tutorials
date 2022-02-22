#include <stdio.h>
#include <conio.h>

int main()
{
    // defining a variable to hold non-negative integers when dealing with huge numbers
    // in case of negative input, it is signed
    long long signed number;
    int i;
    int check;
    int power = 0;

    printf("Enter an integer: ");
    scanf("%lld", &number);

    // check if the number is less than 2
    if (number < 2)
    {
        printf("The number does not have a prime factorization\n");
        printf("Press any key to exit...");
        getch();
        return 0;
    }

    printf("Prime Factors\n");
    for (i = 2; number != 1; i++)
    {
        if (number % i == 0)
        {
            power++;
            number /= i;
            if (power == 1)
            {
                printf("%d", i);
            }
            check = i--;
        }

        if (check == i)
        {
            if (power != 1)
            {
                printf(" ^ %d", power);
            }
            printf("\n");
            power = 0;
        }
    }
    if (power != 1)
    {
        printf(" ^ %d", power);
    }
    printf("\nPress any key to exit...");
    getch();
    return 0;
}
