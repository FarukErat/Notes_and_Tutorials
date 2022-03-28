#include <stdio.h>

/**
 * @brief the program to clarify what happens
 * when a larger variable is assigned to a smaller variable
 */
int main()
{
    unsigned num = 'b'; // 'b' stands for 98 in ascii
    char ch = (char)num; // cast the unsigned to char
    printf("%c\n", ch); // b
    ch = (char)(num + 1); // cast the unsigned to char with adding 1
    printf("%c\n", ch); // c
    ch = (char)(num + 1 + 256); // since the capacity of char is 256, adding 256 will overflow and will return the same as the above
    printf("%c\n", ch); // c
    ch = (char)(num + 2 + 256); // the same as above
    printf("%c\n", ch); // d

    return 0;
}
