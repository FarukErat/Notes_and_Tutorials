#pragma once
#ifndef SMALLEST_PRIME_FACTOR
#define SMALLEST_PRIME_FACTOR

#include <stdio.h> // fprintf(), stderr
#include <stdint.h> // uint64_t
#include <math.h> // sqrt()
#include <stdlib.h> // malloc(), free()
#include <windows.h> // DWORD, HANDLE, LPVOID, INFINITE, CreateThread(), WaitForSingleObject(), CloseHandle()

typedef struct {
    uint64_t n;
    uint64_t start;
    uint64_t end;
    uint64_t result;
    int found;
} ThreadData;

DWORD WINAPI thread_func(LPVOID lpParam) {
    ThreadData* data = (ThreadData*)lpParam;

    for (uint64_t i = data->start; i <= data->end; i++) {
        if (data->n % i == 0) {
            data->result = i;
            data->found = 1;
            return 0;
        }
    }

    return 0;
}

uint64_t smallest_prime_factor_in_range(uint64_t n, uint64_t start, uint64_t end) {
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

uint64_t smallest_prime_factor_in_range_async(uint64_t n, uint64_t start, uint64_t end) {
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
    uint64_t range = (sqrt_n - start) / num_threads;

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

#endif // SMALLEST_PRIME_FACTOR
