#ifndef DISPLAY_BITS_H
#define DISPLAY_BITS_H

#include <stdio.h>
#include <limits.h> /* CHAR_BIT */

const int sizeOfInt = (int)(CHAR_BIT * sizeof(void *));

void displayBits(unsigned value)
{
    unsigned mask = 1 << (CHAR_BIT * sizeof(unsigned) - 1);
    /* mask in binary: 10000000 00000000 00000000 00000000 */
    /* to get digits from left to right, the passed value is operated with "and" and mask,
    so that it will produce 1 if the leftmost digit is 1 and 0 if it is 0 */
    for (unsigned c = 1; c <= CHAR_BIT * sizeof(unsigned); c++)
    {
        /* puts leftmost digit */
        putchar(value & mask ? '1' : '0');
        /* then value is left-shifted to print from left to right */
        /* new rightmost is 0 */
        value <<= 1; /* value = value << 1; */
        /* seperate bits byte by byte */
        if (c % CHAR_BIT == 0)
            putchar(' ');
    }
    putchar('\n');
}

#endif // DISPLAY_BITS_H
