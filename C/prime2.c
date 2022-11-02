#include <stdio.h>
#include <conio.h>

int main()
{
    long long int number;
    int divider = 2;
    int lastDivider = 1;
    int power = 0;

    // get the number from the user and check if the assignment was successful
    printf("Prime Factors of ");
    if (scanf("%lld", &number) != 1)
    {
        printf("Invalid input.\n");
        printf("Press any key to exit...");
        getch();
        return 1;
    }

    // special case for -1, 0 and 1
    if (number == -1 || number == 0 || number == 1)
    {
        printf("-------------\n");
        printf("%d\n", number);
        printf("-------------\n");
        printf("Press any key to exit...");
        getch();
        return 0;
    }

    // convert negative numbers to positive and print the sign
    printf("-------------");
    if (number < 0)
    {
        number = -number;
        printf("\n-1");
    }

    // main loop
    while (number != 1)
    {
        // check if the divider is a factor of the number
        if (number % divider == 0)
        {
            // if so divide the number by the divider
            number = number / divider;
            // increase the power of the divider if it is the same as the last divider
            if (divider == lastDivider)
                power++;
            else
            {
                // if not, there is a new divisor
                // update the last divider and print the exponent of the previous divider
                lastDivider = divider;
                if (power > 1)
                    printf(" ^ %d", power);
                printf("\n%d", divider);
                // since the divider is a new divisor, the power is 1
                power = 1;
            }
        }
        // iterate the divider
        else
            divider++;
    }

    // print the last exponent if not 1
    if (power > 1)
        printf(" ^ %d", power);

    printf("\n-------------");
    printf("\nPress any key to exit...");
    getch();

    return 0;
}
