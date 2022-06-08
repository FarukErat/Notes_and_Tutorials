#include <stdio.h>

/*
being power of two means having only one digit one and others are zero
when substracted one, the numbers digits will change and will not match '&'
however, zero will also lead to 1, so we need to check if n is zero due to a similar logic
*/

int isPowerOfTwo(unsigned n) { return n > 0 && !(n & (n - 1)); }

int main() {
    for (int i = 0; i < 10000; ++i)
        if (isPowerOfTwo(i))
            printf("%d ", i);
    // output: 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192
    return 0;
}
