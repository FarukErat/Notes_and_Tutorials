#include <stdio.h>
#include <stdarg.h>

int sum(int, ...);

int main()
{
    // how many numbers there are
    int element = 5;

    // element number must be sent
    printf("%d", sum(element, 2, 4, 6, 8, 10));

    return 0;
}

int sum(int argNum, ...)
{
    // it declares a pointer to keep sent arguments
    va_list argumentPtr;
    // this function initializes argumentPtr to point to the first argument
    // allocates memory
    va_start(argumentPtr, argNum);

    int i;
    int addition = 0;

    for (i = 0; i < argNum; i++)
    {
        // this function gets the next argument from argumentPtr by iterating
        addition += va_arg(argumentPtr, int);
    }

    // it gives the memory the pointer uses to the system back
    va_end(argumentPtr);
    return addition;
}
