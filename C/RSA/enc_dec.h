#pragma once
#ifndef RSA_UTIL
#define RSA_UTIL

#define MIN_PRIME 10000
#define MAX_PRIME 100000

#include <stdlib.h> // For rand() and srand()
#include <stdint.h> // For uint64_t
#include <time.h> // For time()

// Euclidean algorithm to find the greatest common divisor of two numbers
// For example, given num1 = 24 and num2 = 18, the gcd(24, 18) = 6
uint64_t gcd(uint64_t num1, uint64_t num2) {
    if (num2 == 0) {
        return num1;
    }
    else {
        return gcd(num2, num1 % num2);
    }
}

// (base^exponent % mod) using exponentiation by squaring algorithm
// For example, given base = 5, exponent = 3 and mod = 13, dividing 5^3 = 125 by 13 leaves a remainder of c = 8.
uint64_t mod_exp(uint64_t base, uint64_t exponent, uint64_t mod) {
    if (base >= mod) {
        return -1;
    }
    if (mod == 1 || base == 0) {
        return 0;
    }
    if (exponent == 0 || base == 1) {
        return 1;
    }
    uint64_t result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {// If exponent is odd, multiply base with the result
            result = (result * base) % mod;
        }
        exponent = exponent >> 1; // exponent = exponent / 2
        base = (base * base) % mod; // base = base^2 % mod
    }
    return result;
}

// Generate a random prime number in [min, max]
uint64_t generate_random_prime(uint64_t min, uint64_t max) {
    srand(time(NULL));

    uint64_t num;
    int is_prime = 0;

    while (!is_prime) {
        num = rand() % (max - min + 1) + min;
        is_prime = 1;
        for (uint64_t i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    return num;
}

// Generate RSA keys
void generate_rsa_keys(uint64_t* exponent1, uint64_t* exponent2, uint64_t* product) {
    uint64_t prime1 = generate_random_prime(MIN_PRIME, (MAX_PRIME + MIN_PRIME) / 2);
    uint64_t prime2 = generate_random_prime((MAX_PRIME + MIN_PRIME) / 2, MAX_PRIME);

    *product = prime1 * prime2;

    // since prime1 and prime2 are prime numbers, they have 1 as a greatest common divisor in [1, n-1]
    uint64_t phi_n = (prime1 - 1) * (prime2 - 1);

    // Choose a random public exponent exponent1 such that 1 < exponent1 < φ(n) and gcd(exponent1, φ(n)) = 1
    do {
        *exponent1 = rand() % (phi_n - 2) + 2; // exponent1 should be greater than 1 and less than φ(n)
    } while (gcd(*exponent1, phi_n) != 1);

    // Compute private exponent exponent2 such that (exponent2 * exponent1) % φ(n) = 1
    *exponent2 = 1;
    while ((*exponent2 * (*exponent1)) % phi_n != 1) {
        *exponent2 += 1;
    }
}

uint64_t rsa_encrypt(uint64_t message, uint64_t exponent, uint64_t mod) {
    return mod_exp(message, exponent, mod);
}

uint64_t rsa_decrypt(uint64_t ciphertext, uint64_t exponent, uint64_t mod) {
    return mod_exp(ciphertext, exponent, mod);
}


#endif // RSA_UTIL
