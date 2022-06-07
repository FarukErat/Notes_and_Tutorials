#include <stdio.h>

int repeat = 1;

int main()
{
    if (repeat-- == 0)
    {
        return 0;
    }

    printf("%d\n", repeat);

    return main();
}
