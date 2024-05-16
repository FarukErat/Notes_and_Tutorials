#include <stdio.h>
#include <stdint.h>

#include "pub_to_priv.h"


int main() {
    uint64_t exponent1 = 6427, product = 4168061; // obtain these values from the public key
    uint64_t prime1, prime2; // Prime factors of product (prime1 and prime2 are typically not known in practice)

    prime1 = smallest_prime_factor(product);
    prime2 = product / prime1;

    // Calculate Euler's totient function φ(product)
    uint64_t phi_n = (prime1 - 1) * (prime2 - 1);

    // Calculate the private key 'exponent2' using the modular inverse of 'exponent1' modulo 'φ(product)'
    uint64_t exponent2 = mod_inverse(exponent1, phi_n);

    printf("Private Key (exponent2, product): (%llu, %llu)\n", exponent2, product);

    return 0;
}
