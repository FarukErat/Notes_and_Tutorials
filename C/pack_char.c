#include <stdio.h>
#include <conio.h>
#include <limits.h>

typedef struct
{
    char first;
    char second;
    char third;
    char fourth;
} FourChar;

unsigned packChar(char ch1, char ch2, char ch3, char ch4);
void displayBits(unsigned value);
FourChar unpackChar(unsigned value);

int main()
{
    char ch1, ch2, ch3, ch4;
    printf("First character : ");
    ch1 = getche();
    printf("\nSecond character: ");
    ch2 = getche();
    printf("\nThird character : ");
    ch3 = getche();
    printf("\nFourth character: ");
    ch4 = getche();
    unsigned packed = packChar(ch1, ch2, ch3, ch4);
    FourChar unpacked = unpackChar(packed);
    printf("\n");
    printf("Bits of the characters:\n");
    displayBits(ch1);
    displayBits(ch2);
    displayBits(ch3);
    displayBits(ch4);
    printf("Bits of the packed value\n");
    displayBits(packed);
    printf("First character : %c\n", unpacked.first);
    printf("Second character: %c\n", unpacked.second);
    printf("Third character : %c\n", unpacked.third);
    printf("Fourth character: %c\n", unpacked.fourth);
    printf("%d\n", packed);
    return 0;
}

unsigned packChar(char ch1, char ch2, char ch3, char ch4)
{
    unsigned packed = 0;
    packed = packed | ch4;
    packed = packed | (ch3 << CHAR_BIT);
    packed = packed | (ch2 << CHAR_BIT * 2);
    packed = packed | (ch1 << CHAR_BIT * 3);
    return packed;
}

FourChar unpackChar(unsigned value)
{
    FourChar result;
    // the sizes of char and unsigned are different, however, it will NOT affect the result
    // it overflows and returns the same value as the first character
    unsigned oneByte = 255; // 2^8  - 2^0  = 00000000 00000000 00000000 11111111
    result.first = value >> CHAR_BIT * 3 & oneByte;
    result.second = value >> CHAR_BIT * 2 & oneByte;
    result.third = value >> CHAR_BIT & oneByte;
    result.fourth = value & oneByte;
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
