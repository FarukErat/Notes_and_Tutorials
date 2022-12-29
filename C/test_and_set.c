#include <stdio.h>

typedef enum
{
    false,
    true
} bool;

bool testAndSet(bool *target)
{
    bool rv = *target;
    *target = true;
    return rv;
}

int main()
{
    bool flag = false;
    bool rv = testAndSet(&flag);
    printf("flag = %d, rv = %d\n", flag, rv);

    rv = testAndSet(&flag);
    printf("flag = %d, rv = %d\n", flag, rv);

    return 0;
}
