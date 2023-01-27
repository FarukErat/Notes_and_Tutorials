#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>

long long unsigned packChar(char *input);
char *unpackChar(long long unsigned packed);

int main()
{
    char input[8];
    printf("Enter 8 characters : ");
    for (size_t i = 0; i < 8; i++)
    {
        input[i] = getche();
    }
    unsigned long long packed = packChar(input);
    printf("\n%llu\n", packed);
    char *unpacked = unpackChar(packed);
    printf("%s\n", unpacked);
    free(unpacked);
    return 0;
}

long long unsigned packChar(char *input)
{
    long long unsigned packed = 0;
    for (size_t i = 0; i < 8; i++)
    {
        packed <<= 8; // shift left by 8 bits (1 byte)
        packed |= input[i];
    }
    return packed;
}

char *unpackChar(long long unsigned packed)
{
    char *result = (char *)malloc(sizeof(char) * 9);
    // the sizes of char and unsigned are different, however, it will NOT affect the result
    // it overflows and returns the same value as the first character
    unsigned oneByte = 255;
    for (size_t i = 0; i < 8; i++)
    {
        result[i] = packed >> CHAR_BIT * (7 - i) & oneByte;
    }
    result[8] = '\0';

    return result;
}