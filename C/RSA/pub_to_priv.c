#include <stdio.h>
#include <stdint.h>

#include "pub_to_priv.h"

uint64_t main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <exponent> <product>\n", argv[0]);
        return 1;
    }

    uint64_t exponent1 = strtoull(argv[1], NULL, 10);
    uint64_t product = strtoull(argv[2], NULL, 10);

    uint64_t exponent2 = find_unknown_exponent(exponent1, product);

    printf("%llu", exponent2);

    return 0;
}
