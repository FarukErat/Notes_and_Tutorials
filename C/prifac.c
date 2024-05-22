#include <stdio.h>  // printf()
#include <math.h>   // sqrt()
#include <string.h> // strcpy()
#include <ctype.h>  // isdigit()
// #include <stdlib.h> // strtoull() // not used to avoid the overhead of error checking

typedef long long unsigned llu;

/**
 * @brief Removes leading zeros from the input
 *
 * @param input string to remove leading zeros from
 */
void formatInput(const char** input) {
    while ((*input)[0] == '0') {
        (*input)++;
    }
}

/**
 * @brief Checks if the input is numeric
 *
 * @param str string to check
 * @return int 1 if numeric, 0 if not
 */
int isNumeric(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * @brief Checks if the input is in the range of a long long unsigned int
 *
 * @param str string to check
 * @return int 1 if in range, 0 if not
 */
int isInRange(const char* str) {
    unsigned size = strlen(str);
    if (size > 20) {
        return 0;
    }
    if (size < 20) {
        return 1;
    }

    char* biggestLLU = "18446744073709551615";
    int j = 0;
    while (j < 20) {
        if (str[j] > biggestLLU[j]) {
            return 0;
        }
        else if (str[j] < biggestLLU[j]) {
            return 1;
        }
        j++;
    }
    return 1;
}

/**
 * @brief Converts the input to a long long unsigned int,
 * instead of using strtoull() to avoid the overhead of error checking
 *
 * @param str string to convert
 * @return llu
 */
llu str_to_llu(const char* str) {
    llu result = 0;
    int i = 0;
    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

/**
 * @brief Prints the prime factors of the input
 *
 * @param input string to print the prime factors of
 */
void printPrimeFactors(const char* str) {
    formatInput(&str);
    if (!isInRange(str)) {
        printf("Input out of range!\n");
        return;
    }
    if (!isNumeric(str)) {
        printf("Input is not a number!\n");
        return;
    }

    llu number = str_to_llu(str);
    llu endSearch;
    llu divider = 3;
    llu lastDivider = 1;
    unsigned power = 0;

    // handle 1, 2 and 3
    printf("\nPrime Factors of %llu\n", number);
    printf("----------------");

    if (number < 4) {
        printf("\n%llu\n", number);
        printf("----------------\n");
        return;
    }

    // handle even numbers
    if (number % 2 == 0) {
        printf("\n2");
        do {
            number /= 2;
            power++;
        } while (number % 2 == 0);
        if (power > 1)
            printf(" ^ %d", power);
        power = 0;
    }

    // since pairs of factors are found, the loop can stop at the square root of the number
    endSearch = sqrt(number);
    // main loop
    while (number != 1) {
        // check if the divider is a factor of the number
        if (number % divider == 0) {
            // if so divide the number by the divider
            number = number / divider;
            endSearch = sqrt(number);

            // increase the power of the divider if it is the same as the last divider
            if (divider == lastDivider) {
                power++;
            }
            else {
                // if not, there is a new divisor
                // update the last divider and print the exponent of the previous divider
                lastDivider = divider;
                if (power > 1) {
                    printf(" ^ %d", power);
                }
                printf("\n%llu", divider);

                // since the divider is a new divisor, the power is 1
                power = 1;
            }
        }
        // iterate the divider
        else {
            divider += 2; // only odd numbers can be divisors
            if (divider > endSearch) {
                // jump to the end since there cannot be any more divisors in between
                divider = number;
            }
        }
    }

    // print the last exponent if not 1
    if (power > 1) {
        printf(" ^ %d", power);
    }

    printf("\n----------------\n");
}

void displayHelp(const char* appName) {
    printf("Usage: %s <number>\n\
\n\
Description: \n\
Calculates and prints the prime factors of a given number.\n\
\n\
Arguments: \n\
- <number>: The integer for which prime factors are to be calculated.\n\
- max-prime: The biggest prime number representable by a long long unsigned int. (18446744073709551557)\n\
- max-number: The biggest representable number by a long long unsigned int.      (18446744073709551615)\n\
\n\
Options: \n\
- -h, --help: Display this help message.\n\
\n\
Examples: \n\
1. To calculate the prime factors of a specific number: \n\
   prifac 123456 \n\
2. To calculate the prime factors of the biggest prime number: \n\
   prifac max-prime \n\
3. To calculate the prime factors of the biggest representable number: \n\
   prifac max-number \n\
4. To display the help message: \n\
   prifac -h\n\
\n\
Note: \n\
- For extremely large numbers, the program might take longer to compute. \n\
- Use Ctrl+C to terminate the program if it's taking too long for calculation.", appName);
}

int main(const int argc, const char** argv) {
    // switch instead of if-else to allow for more arguments in the future
    switch (argc) {
    case 2:
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            displayHelp(argv[0]);
            break;
        }
        if (strcmp(argv[1], "max-prime") == 0) {
            printPrimeFactors("18446744073709551557");
            break;
        }
        if (strcmp(argv[1], "max-number") == 0) {
            printPrimeFactors("18446744073709551615");
            break;
        }
        printPrimeFactors(argv[1]);
        break;
    default:
        displayHelp(argv[0]);
        break;
    }
    return 0;
}
