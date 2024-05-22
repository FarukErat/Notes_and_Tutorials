#pragma once
#ifndef PUB_TO_PRIV
#define PUB_TO_PRIV

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    uint64_t n;
    uint64_t start;
    uint64_t end;
    uint64_t result;
    int found;
} ThreadData;

uint64_t find_smallest_prime_factor_in_range(uint64_t n, uint64_t start, uint64_t end) {
    if (n <= 1 || start > end) {
        return 0;
    }

    uint64_t sqrt_n = sqrt(n);
    if (end > sqrt_n) {
        end = sqrt_n;
    }
    for (uint64_t i = start; i <= end; i += 2) {
        if (n % i == 0) {
            return i;
        }
    }

    return n;
}

DWORD WINAPI thread_func(LPVOID arg) {
    ThreadData* data = (ThreadData*)arg;
    uint64_t result = find_smallest_prime_factor_in_range(data->n, data->start, data->end);

    if (result != data->n) {
        data->result = result;
        data->found = 1;
    }

    return 0;
}

uint64_t find_smallest_prime_factor(uint64_t n) {
    if (n <= 1) {
        return 0;
    }

    if (n % 2 == 0) {
        return 2;
    }

    int num_threads = 8;
    HANDLE* threads = (HANDLE*)malloc(num_threads * sizeof(HANDLE));
    ThreadData* thread_data = (ThreadData*)malloc(num_threads * sizeof(ThreadData));

    if (threads == NULL || thread_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    uint64_t sqrt_n = (uint64_t)sqrt(n);
    uint64_t range = (sqrt_n - 3) / num_threads;
    uint64_t start = 3;

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].n = n;
        thread_data[i].start = start + i * range;
        thread_data[i].end = (i == num_threads - 1) ? sqrt_n : (start + (i + 1) * range - 1);
        thread_data[i].result = n;
        thread_data[i].found = 0;

        threads[i] = CreateThread(NULL, 0, thread_func, &thread_data[i], 0, NULL);
        if (threads[i] == NULL) {
            fprintf(stderr, "Error creating thread %d\n", i);
            free(threads);
            free(thread_data);
            exit(EXIT_FAILURE);
        }
    }

    uint64_t smallest_prime_factor = n;
    for (int i = 0; i < num_threads; i++) {
        WaitForSingleObject(threads[i], INFINITE);
        CloseHandle(threads[i]);
        if (thread_data[i].found && thread_data[i].result < smallest_prime_factor) {
            smallest_prime_factor = thread_data[i].result;
        }
    }

    free(threads);
    free(thread_data);

    return smallest_prime_factor;
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

#endif // PUB_TO_PRIV
