#pragma once
#ifndef PUB_TO_PRIV
#define PUB_TO_PRIV

#include <stdint.h> // uint64_t

#include "smallest_prime_factor.h"

// modular multiplicative inverse of 'a' modulo 'm'
uint64_t mod_inverse(uint64_t a, uint64_t m) {
    int64_t m0 = m, t, q;
    int64_t x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    // Apply extended Euclidean algorithm to find the modular inverse
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now; process same as Euclid's algorithm
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

uint64_t find_unknown_exponent(uint64_t exponent, uint64_t product) {
    uint64_t prime1, prime2; // Prime factors of product (prime1 and prime2 are typically not known in practice)

    prime1 = smallest_prime_factor_in_range_async(product, 2, product);
    prime2 = product / prime1;

    uint64_t phi_n = (prime1 - 1) * (prime2 - 1);

    uint64_t unknownExponent = mod_inverse(exponent, phi_n);

    return unknownExponent;
}

#endif // PUB_TO_PRIV
