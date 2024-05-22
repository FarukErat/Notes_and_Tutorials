#include <stdio.h>
#include <stdint.h>

#include "pub_to_priv.h"

uint64_t main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <exponent1> <product>\n", argv[0]);
        return 0;
    }

    uint64_t exponent1 = strtoull(argv[1], NULL, 10);
    uint64_t product = strtoull(argv[2], NULL, 10);

    uint64_t exponent2 = exponent_of_missing_key(exponent1, product);

    printf("Private Key (exponent2, product): (%llu, %llu)\n", exponent2, product);

    return exponent2;
}
