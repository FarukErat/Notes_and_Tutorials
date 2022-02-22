#include <stdio.h>

#define SIZE 4

int main()
{
    int var1 = 10, var2 = 20, var3 = 30, var4 = 40, *ptr[SIZE];

    ptr[0] = &var1;
    ptr[1] = &var2;
    ptr[2] = &var3;
    ptr[3] = &var4;

    for (int i = 0; i < SIZE; i++)
    {
        printf("Value of var[%d] = %d\n", i, *(*(ptr + i)));
        // ptr and ptr + i are pointers of variables
        // *(ptr + i) is the pointer of the pointers
        // *(*(ptr + i)) is the value stored on the adresses
    }

    return 0;
}