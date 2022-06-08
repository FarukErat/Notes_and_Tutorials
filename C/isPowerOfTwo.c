#include <stdio.h>

/*
being power of two means having only one digit one and others are zero
when substracted one, the numbers digits will change and will not match '&'
however, zero will also lead to 1, so we need to check if n is zero due to a similar logic

00100100 = 36
&
00100011 = 35
= 1

00100000 = 32
&
00011111 = 31
= 0

00000000 = 0
&
10000001 = 1
= 0 // be careful here because 0 is not a power of two

10000001 = -1
&
10000010 = -2
= 1
*/

int isPowerOfTwo(unsigned n) { return n > 0 && !(n & (n - 1)); }

int main() {
    for (int i = 0; i < 10000; ++i)
        if (isPowerOfTwo(i))
            printf("%d ", i);
    // output: 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192
    return 0;
}
