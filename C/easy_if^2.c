#include <stdio.h>

int main()
{
    int y;
    int x = 3;

    y = x >= 5 ?  20 : x;
    
    /* 
    if(x>=5)
    y=20
    
    else
    y=x
    */

    printf("%d", y);

    return 0;
}