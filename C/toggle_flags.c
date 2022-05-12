#include <stdio.h>

int main()
{
    int flag = 2; // initially 2, meaning true, since any number that is not 0 is true
    printf("%d\n", flag);

    flag = !flag; // toggled to 0, which is the only number to denote false
    printf("%d\n", flag);

    flag = !flag; // toggled to 1, default number of true
    printf("%d\n", flag);

    // if (flag)  // if (flag != 0)
    //     flag = 0;
    // else
    //     flag = 1;

    return 0;
}
