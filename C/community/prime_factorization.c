#include <stdio.h>  // printf()
#include <stdlib.h> // strtoull()
#include <math.h>   // sqrt()
#include <string.h> // strcpy()

typedef long long unsigned llu;

/**
 * @brief Removes leading zeros from the input
 *
 * @param input string to remove leading zeros from
 */
void formatInput(char *input);

/**
 * @brief Checks if the input is numeric
 *
 * @param str string to check
 * @return int 1 if numeric, 0 if not
 */
int isNumeric(char *str);

/**
 * @brief Checks if the input is in the range of a long long unsigned int
 *
 * @param str string to check
 * @return int 1 if in range, 0 if not
 */
int isInRange(char *str);

/**
 * @brief Checks if the input is valid (numeric and in range)
 *
 * @param input string to check
 * @return int 1 if valid, 0 if not
 */
int isValid(char *input);

/**
 * @brief Prints the prime factors of the input
 *
 * @param input string to print the prime factors of
 */
void printPrimeFactors(char *input);

int main(int argc, char *argv[])
{
    // switch instead of if-else to allow for more arguments in the future
    switch (argc)
    {
    case 2:
        printPrimeFactors(argv[1]);
        break;
    default:
        printf("Usage: prifac <number>\n");
        break;
    }
    return 0;
}

void formatInput(char *input)
{
    while (input[0] == '0')
    {
        // remove leading zeros
        strcpy(input, input + 1);
    }
}

int isNumeric(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isInRange(char *str)
{
    char *biggestLLU = "18446744073709551615";
    int j = 0;
    while (j < 20)
    {
        if (str[j] > biggestLLU[j])
        {
            return 0;
        }
        else if (str[j] < biggestLLU[j])
        {
            return 1;
        }
        j++;
    }
    return 1;
}

int isValid(char *str)
{
    unsigned size = strlen(str);
    if (size > 20)
        return 0;
    if (size == 20 && !isInRange(str))
        return 0;
    if (!isNumeric(str))
        return 0;
    return 1;
}

void printPrimeFactors(char *input)
{
    formatInput(input);
    if (!isValid(input))
    {
        printf("Invalid input!\n");
        return;
    }

    llu number = strtoull(input, NULL, 10);
    // since pairs of factors are found, the loop can stop at the square root of the number
    llu endSearch;
    llu divider = 3;
    llu lastDivider = 1;
    unsigned power = 0;

    printf("\nPrime Factors of %llu\n", number);
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
