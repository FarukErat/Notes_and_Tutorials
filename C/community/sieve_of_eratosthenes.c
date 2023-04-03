//TODO: errs with 6 and some more

#include <stdio.h>   // printf()
#include <stdlib.h>  // malloc(), free()
#include <math.h>    // sqrt()
#include <string.h>  // strcpy()
#include <stdbool.h> // bool, true, false
// #include <stdlib.h> // strtoull()

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
 * @brief Converts the input to a long long unsigned int,
 * instead of using strtoull() to avoid the overhead of error checking
 *
 * @param str string to convert
 * @return llu
 */
llu str_to_llu(char *str);

/**
 * @brief Modifies the input array to contain the prime factors of the input
 *
 * @param n number to find the prime factors till
 * @param is_prime array to store the prime numbers in
 */
void sieve(llu n, bool *is_prime);

/**
 * @brief Finds the prime factors of the input
 *
 * @param n number to find the prime factors of
 * @param num_factors pointer to store the number of prime factors in
 * @return int* array containing the prime factors
 */
llu *prime_factors(llu n, int *num_factors);

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
    if (size == 20)
        if (!isInRange(str))
            return 0;
    if (!isNumeric(str))
        return 0;
    return 1;
}

llu str_to_llu(char *str)
{
    llu result = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

void sieve(llu n, bool *is_prime)
{
    n = (llu)sqrt(n);

    // Initialize all numbers as prime
    for (llu i = 2; i <= n; i++)
    {
        is_prime[i] = true;
    }

    // except 0 and 1
    is_prime[0] = false;
    is_prime[1] = false;

    // Mark multiples of primes as composite
    llu limit = sqrt(n);
    for (llu i = 2; i <= limit; i++)
    {
        if (is_prime[i])
        {
            for (llu j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

llu *prime_factors(llu n, int *num_factors)
{
    bool *is_prime = malloc((n + 1) * sizeof(bool));
    sieve(n, is_prime);

    llu *factors = malloc(n * sizeof(llu));
    int factorIndex = 0;
    int i = 2;
    while (n > 1)
    {
        if (is_prime[i] && n % i == 0)
        {
            factors[factorIndex++] = i;
            n /= i;
        }
        else
        {
            i++;
        }
    }

    free(is_prime);
    *num_factors = factorIndex;
    return factors;
}

void printPrimeFactors(char *str)
{
    // remove leading zeros
    formatInput(str);

    // check if input is valid
    if (!isValid(str))
    {
        printf("Invalid input!\n");
        return;
    }

    // convert input to long long unsigned int
    llu number = str_to_llu(str);

    // print the prime factors
    printf("\nPrime Factors of %llu\n", number);
    printf("----------------");

    // handle numbers smaller than 4
    if (number < 4)
    {
        printf("\n%lld\n", number);
        printf("----------------\n");
        return;
    }

    // handle even numbers
    unsigned power = 0;
    int primeIndex = 0;

    if (number % 2 == 0)
    {
        primeIndex = 1;
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

    // main loop
    llu lastDivider = 1;
    int factorCount;
    llu *primes = prime_factors(number, &factorCount);
    llu divider = primes[primeIndex];

    while (number != 1)
    {
        // check if the divider is a factor of the number
        if (number % divider == 0)
        {
            // if so divide the number by the divider
            number = number / divider;

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
            primeIndex++;
            divider = primes[primeIndex];
            if (factorCount == primeIndex)
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
