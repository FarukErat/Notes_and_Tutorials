#include <stdio.h>

#include "smallest_prime_factor.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number> <lowerBound> <upperBound>\n", argv[0]);
        return 1;
    }

    uint64_t number = strtoull(argv[1], NULL, 10);
    uint64_t lowerBound = strtoull(argv[2], NULL, 10);
    uint64_t upperBound = strtoull(argv[3], NULL, 10);

    uint64_t smallest_prime = smallest_factor_in_range_async(number, lowerBound, upperBound);
    printf("%llu", smallest_prime);

    return 0;
}
