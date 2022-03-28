#include <stdio.h>
#include <conio.h>
#include <limits.h>

typedef struct
{
    char left;
    char right;
} TwoChar;

unsigned packChar(char ch1, char ch2);
void displayBits(unsigned value);
TwoChar unpackChar(unsigned value);

int main()
{
    char ch1, ch2;
    printf("First character : ");
    ch1 = getche();
    printf("\nSecond character: ");
    ch2 = getche();
    unsigned packed = packChar(ch1, ch2);
    TwoChar unpacked = unpackChar(packed);
    printf("\n");
    printf("Bits of the characters:\n");
    displayBits(ch1);
    displayBits(ch2);
    printf("Bits of the packed value\n");
    displayBits(packed);
    printf("First character : %c\n", unpacked.left);
    printf("Second character: %c\n", unpacked.right);

    return 0;
}

unsigned packChar(char ch1, char ch2)
{
    unsigned result = 0;
    // shift ch1 to the left 16 bits and then OR it with ch2 to combine them into one unsigned int
    result = (ch1 << CHAR_BIT * sizeof(unsigned) / 2) | ch2;
    return result;
}

TwoChar unpackChar(unsigned value)
{
    TwoChar result;
    unsigned oneByte = 255;    // 2^8 - 1 = 00000000 00000000 00000000 11111111
    result.left = value >> 16; // right shift 16 bits to eliminate the right character
    result.right = value & oneByte;
    return result;
}

void displayBits(unsigned value)
{
    // CHAR_BIT: number of bits in a byte
    unsigned c;
    // declare a variable of 32 bits(4 bytes) by shifting 1 by 31
    unsigned fourByte = 1 << (CHAR_BIT * sizeof(unsigned) - 1); // 10000000 00000000 00000000 00000000
    // 32 due to the bits of fourByte
    for (c = 1; c <= CHAR_BIT * sizeof(unsigned); c++)
    {
        // value's leftmost bit is checked as it is shifted due to the bits of fourByte
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
