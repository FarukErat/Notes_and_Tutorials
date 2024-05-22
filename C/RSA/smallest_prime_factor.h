#pragma once
#ifndef SMALLEST_PRIME_FACTOR
#define SMALLEST_PRIME_FACTOR

#include <stdio.h> // fprintf(), stderr
#include <stdint.h> // uint64_t
#include <math.h> // sqrt()
#include <stdlib.h> // malloc(), free()
#include <windows.h> // DWORD, HANDLE, LPVOID, INFINITE, CreateThread(), WaitForSingleObject(), CloseHandle()

typedef struct {
    uint64_t number;
    uint64_t lowerBound;
    uint64_t upperBound;
    uint64_t result;
    int found;
} ThreadData;

uint64_t smallest_odd_factor_in_range(uint64_t number, uint64_t lowerBound, uint64_t upperBound) {
    if (upperBound > number) {
        upperBound = number;
    }

    if ((lowerBound % 2 == 0) && (lowerBound + 1 <= number)) {
        ++lowerBound;
    }

    if (lowerBound > upperBound) {
        return 0;
    }

    for (uint64_t i = lowerBound; i <= upperBound; i += 2) {
        if (number % i == 0) {
            return i;
        }
    }

    return 0;
}

DWORD WINAPI thread_func(LPVOID lpParam) {
    ThreadData* data = (ThreadData*)lpParam;

    data->result = smallest_odd_factor_in_range(data->number, data->lowerBound, data->upperBound);
    if (data->result != 0) {
        data->found = 1;
    }

    return 0;
}

uint64_t smallest_factor_in_range_async(uint64_t number, uint64_t lowerBound, uint64_t upperBound) {
    if (lowerBound > upperBound) {
        return 0;
    }

    int num_threads = 64;
    HANDLE* threads = (HANDLE*)malloc(num_threads * sizeof(HANDLE));
    ThreadData* thread_data = (ThreadData*)malloc(num_threads * sizeof(ThreadData));

    if (threads == NULL || thread_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    uint64_t range = (upperBound - lowerBound) / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        thread_data[i].number = number;
        thread_data[i].lowerBound = lowerBound + i * range;
        thread_data[i].upperBound = i == (num_threads - 1) ? upperBound : lowerBound + (i + 1) * range; // due to int truncation
        thread_data[i].result = 0;
        thread_data[i].found = 0;

        threads[i] = CreateThread(NULL, 0, thread_func, &thread_data[i], 0, NULL);
        if (threads[i] == NULL) {
            fprintf(stderr, "Error creating thread %d\n", i);
            free(threads);
            free(thread_data);
            exit(EXIT_FAILURE);
        }
    }

    uint64_t smallest_prime_factor = 0;
    for (int i = 0; i < num_threads; ++i) {
        WaitForSingleObject(threads[i], INFINITE);
        CloseHandle(threads[i]);
        if (thread_data[i].found) {
            if (smallest_prime_factor == 0) {
                smallest_prime_factor = thread_data[i].result;
            }
            else if (thread_data[i].result < smallest_prime_factor) {
                smallest_prime_factor = thread_data[i].result;
            }
        }
    }

    free(threads);
    free(thread_data);

    return smallest_prime_factor;
}

#endif // SMALLEST_PRIME_FACTOR
