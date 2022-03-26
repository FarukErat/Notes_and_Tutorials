#include <stdio.h>

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
    printf("%10d = ", value);
    unsigned c;
    // declare a variable of 32 bits(4 bytes) by shifting 1 by 31
    unsigned fourByte = 1 << 31; // 10000000 00000000 00000000 00000000
    // 32 due to the bits of fourByte
    for (c = 1; c <= 32; c++)
    {
        // value's and fourByte's left-top bits are compared
        putchar(value & fourByte ? '1' : '0');
        // value is shifted by one
        value <<= 1; // value = value << 1;
        // seperate 8 bits(1 byte)
        if (c % 8 == 0)
            putchar(' ');
    }
    putchar('\n');
}
