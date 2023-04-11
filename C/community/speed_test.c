#include <stdio.h> // printf()
#include <time.h>  // clock_t, clock()

// skip odd numbers
int foo1(int bottom, int top) {
    if (bottom > top) {
        return 0;
    }
    if (bottom % 2 != 0) {
        bottom++;
    }
    int sum = 0;
    for (int i = bottom; i <= top; i += 2) {
        sum += i;
    }
    return sum;
}

// check if even
int foo2(int bottom, int top) {
    if (bottom > top) {
        return 0;
    }
    int sum = 0;
    for (int i = bottom; i <= top; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    return sum;
}

// recursive skip odd numbers
int foo3(int bottom, int top) {
    if (bottom > top) {
        return 0;
    }
    if (bottom % 2 != 0) {
        bottom++;
    }
    return bottom + foo3(bottom + 2, top);
}

// recursive check if even
int foo4(int bottom, int top) {
    int num = 0;
    if (bottom > top) {
        return 0;
    }
    if (bottom % 2 == 0) {
        num = bottom;
    }
    return num + foo4(bottom + 1, top);
}

// measure time of function execution
void testSpeed(int (*foo)(int, int), int bottom, int top, int times) {
    clock_t start, end;
    int result;
    start = clock();
    for (int i = 0; i < times; i++) {
        result = foo(bottom, top);
    }
    end = clock();
    printf("time in ms = %u\n", (unsigned int)(end - start));
    printf("result = %d\n", result);
}

// driver function
int main() {
    // set parameters
    const int till = 100;
    const int times = 1000000;

    printf("Range: 1 to %d\n", till);
    printf("Number of iterations: %d\n\n", times);

    // measure times of functions
    testSpeed(foo1, 1, till, times);
    testSpeed(foo2, 1, till, times);
    testSpeed(foo3, 1, till, times);
    testSpeed(foo4, 1, till, times);

    return 0;
}
