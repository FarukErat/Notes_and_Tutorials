#include <stdio.h> // For printf

#include "enc_dec.h"

int main() {
    uint64_t exponent1, exponent2, product;

    // Generate RSA key pair
    generate_rsa_keys(&exponent1, &exponent2, &product);

    // Display the generated public and private keys
    printf("Generated RSA Key Pair:\n");
    printf("Public Key (exponent1, product): (%llu, %llu)\n", exponent1, product);
    printf("Private Key (exponent2, product): (%llu, %llu)\n", exponent2, product);

    // Encrypt and decrypt a sample message
    uint64_t message = 987654321; // Sample message to be encrypted
    printf("\nOriginal Message: %llu\n", message);

    // Encrypt the message using public key (exponent1, product)
    uint64_t ciphertext = rsa_encrypt(message, exponent1, product);
    if (ciphertext == -1) {
        printf("Error: Message is too large to be encrypted with the given public key\n");
        return 1;
    }
    printf("Encrypted Message (Ciphertext): %llu\n", ciphertext);

    // Decrypt the ciphertext using private key (exponent2, product)
    uint64_t decrypted_message = rsa_decrypt(ciphertext, exponent2, product);
    printf("Decrypted Message: %llu\n", decrypted_message);

    return 0;
}
