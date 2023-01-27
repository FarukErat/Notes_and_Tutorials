#include <stdio.h>

/**
 * @brief the program to clarify what happens
 * when a larger variable is assigned to a smaller variable
 */
int main()
{
    // assignment will start from the leftmost side
    // when a byte is assigned, the next byte will be assigned
    // therefore, char variable will have the value of the last byte
    unsigned num = 'b';         // 'b' stands for 98 in ascii // 00000000 00000000 00000000 1100010
    char ch = (char)num;        // cast the unsigned to char
    printf("%c\n", ch);         // b
    ch = (char)(num + 1);       // cast the unsigned to char with adding 1
    printf("%c\n", ch);         // c
    ch = (char)(num + 1 + 256); // since the capacity of char is 256, adding 256 will overflow and will return the same as the above
    printf("%c\n", ch);         // c
    ch = (char)(num + 2 + 256); // the same as above
    printf("%c\n", ch);         // d
    num <<= 8;                  // shift the value of num by 8 bits // 00000000 00000000 1100010 00000000
    ch = (char)num;             // cast the unsigned to char
    printf("%c\n", ch);         // NULL
    ch += 65;                   // add 65 to the value of ch
    printf("%c\n", ch);         // A

    return 0;
}