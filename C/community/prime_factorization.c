#include <stdio.h>  // printf()
#include <stdlib.h> // atoll()
#include <conio.h>  // getch()
#include <math.h>   // sqrt()
#include <string.h> // strcpy()

typedef long long int lli;

int isValidInput(char *input)
{
    int i = 0;
    while (input[i] != '\0')
    {

        // check if the input is numeric
        if (input[i] < '0' || input[i] > '9')
        {
            return 0;
        }
        i++;
        // greatest number with long long int is 9,223,372,036,854,775,807
        // which is 19 digits long
        if (i > 19)
        {
            return 0;
        }
    }
    return 1;
}

void formatInput(char *input)
{
    while (input[0] == '0')
    {
        // remove leading zeros
        strcpy(input, input + 1);
    }
}

void printPrimeFactors(char *input)
{
    formatInput(input);
    if (!isValidInput(input))
    {
        printf("Invalid input!\n");
        return;
    }

    lli number = atoll(input);
    // since pairs of factors are found, the loop can stop at the square root of the number
    lli endSearch;
    lli divider = 3;
    lli lastDivider = 1;
    unsigned power = 0;

    printf("\nPrime Factors of %lld\n", number);
    printf("----------------");

    if (number < 4)
    {
        printf("\n%lld\n", number);
        printf("----------------\n");
        return;
    }

    // handle even numbers
    if (number % 2 == 0)
    {
        printf("\n2");
        do
        {
            number /= 2;
            power++;
        } while (number % 2 == 0);
        if (power > 1)
            printf(" ^ %d", power);
        power = 0;
    }

    endSearch = sqrt(number);

    // main loop
    while (number != 1)
    {
        // check if the divider is a factor of the number
        if (number % divider == 0)
        {
            // if so divide the number by the divider
            number = number / divider;
            endSearch = sqrt(number);

            // increase the power of the divider if it is the same as the last divider
            if (divider == lastDivider)
            {
                power++;
            }
            else
            {
                // if not, there is a new divisor
                // update the last divider and print the exponent of the previous divider
                lastDivider = divider;
                if (power > 1)
                {
                    printf(" ^ %d", power);
                }
                printf("\n%lld", divider);

                // since the divider is a new divisor, the power is 1
                power = 1;
            }
        }

        // iterate the divider
        else
        {
            divider += 2; // only odd numbers can be divisors
            if (divider > endSearch)
            {
                divider = number;
            }
        }
    }

    // print the last exponent if not 1
    if (power > 1)
    {
        printf(" ^ %d", power);
    }

    printf("\n----------------\n");
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        printPrimeFactors(argv[1]);
    }
    else
    {
        printf("Usage: prifac <number>\n");
    }
    return 0;
}
