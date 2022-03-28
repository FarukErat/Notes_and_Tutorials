#include <stdio.h>
#include <limits.h>

void displayBits(unsigned value);

int main()
{
    unsigned a = 99996754, b = 30;
    displayBits(a);     // 00000101 11110101 11010100 01010010
    displayBits(b);     // 00000000 00000000 00000000 00011110
    displayBits(a | b); // 00000101 11110101 11010100 01011110
    displayBits(a & b); // 00000000 00000000 00000000 00010010
    displayBits(a ^ b); // 00000101 11110101 11010100 01001100
    displayBits(~a);    // 11111010 00001010 00101011 10101101
    return 0;
}

void displayBits(unsigned value)
{
    // CHAR_BIT: number of bits in a byte
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
