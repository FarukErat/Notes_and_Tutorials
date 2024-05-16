#pragma once
#ifndef PUB_TO_PRIV
#define PUB_TO_PRIV

#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t smallest_prime_factor(uint64_t n) {
    if (n % 2 == 0) {
        return 2;
    }

    uint64_t sqrt_n = sqrt(n);
    for (uint64_t i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) {
            return i;
        }
    }

    return n;
}

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
        m = a % m, a = t;
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

#endif // PUB_TO_PRIV
