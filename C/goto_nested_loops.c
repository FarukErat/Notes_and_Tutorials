#include <stdio.h>

int main()
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (i * j > 50)
            {
                goto done; // exit both loops
            }
        }
    }
done:
    printf("%d*%d=%d is greater than 50\n", i, j, i * j);

    return 0;
}
