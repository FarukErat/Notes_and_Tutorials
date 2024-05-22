#include <stdio.h>

#include "smallest_prime_factor.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    uint64_t number = strtoull(argv[1], NULL, 10);

    uint64_t smallest_prime = smallest_prime_factor_in_range_async(number, 2, number);
    printf("Smallest prime factor of %llu is %llu\n", number, smallest_prime);

    return 0;
}
