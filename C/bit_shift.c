#include <stdio.h>

int main()
{
    int a = 20; /* 20 = 010100 */
    int c = 0;
    // when 010100 is one digit shifted, it yields 101000
    c = a << 2; /* 80 = 101000 */
    printf("Left shift - Value of c is %d\n", c);
    // when 101000 is one digit shifted, it yields 000101
    c = a >> 2; /*05 = 000101 */
    printf("Right shift - Value of c is %d\n", c);

    printf("3 x 2^5 = %d\n", 3 << 5);
    return 0;
}
