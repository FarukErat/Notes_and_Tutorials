#include <stdio.h>
#include <limits.h>

void displayBits(unsigned value);

int main()
{
    displayBits(99);       // 00000000 00000000 00000000 01100011
    displayBits(1);        // 00000000 00000000 00000000 00000001
    displayBits(32);       // 00000000 00000000 00000000 00100000
    displayBits(99999999); // 00000101 11110101 11100000 11111111
    return 0;
}

void displayBits(unsigned value)
{
    // CHAR_BIT: number of bits in a byte
    printf("%10d = ", value);
    unsigned c;
    // declare a variable of 32 bits(4 bytes) by shifting 1 by 31
    unsigned fourByte = 1 << CHAR_BIT * sizeof(unsigned) - 1; // 10000000 00000000 00000000 00000000
    // 32 due to the bits of fourByte
    for (c = 1; c <= CHAR_BIT * sizeof(unsigned); c++)
    {
        // value's and fourByte's leftmost bits are compared
        putchar(value & fourByte ? '1' : '0');
        // value is shifted by one
        // 0 is added to the rightmost
        value <<= 1; // value = value << 1;
        // seperate 8 bits(1 byte)
        if (c % 8 == 0)
            putchar(' ');
    }
    putchar('\n');
}
