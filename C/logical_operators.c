#include <stdio.h>

int main()
{
    for (int left = 0; left <= 1; left++)
    {
        for (int right = 0; right <= 1; right++)
        {
            printf("%d || %d = %d\n", left, right, left || right);
            printf("%d && %d = %d\n", left, right, left && right);
            printf("%d ^ %d  = %d\n", left, right, left ^ right);
            printf("\n");
        }
    }

    return 0;
}
