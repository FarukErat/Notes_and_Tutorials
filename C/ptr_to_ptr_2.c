#include <stdio.h>

int main()
{
    int a = 1;
    int *p = &a;
    int **pp = &p;
    printf("p:\t%d\n", p);  // 6422300
    printf("&p:\t%d\n", &p); // 6422296
    printf("*p:\t%d\n", *p); // 1
    printf("\n");
    printf("pp:\t%d\n", pp);   // 6422296
    printf("&pp:\t%d\n", &pp);  // 6422292
    printf("*pp:\t%d\n", *pp);  // 6422300
    printf("**pp:\t%d\n", **pp); // 1

    return 0;
}
