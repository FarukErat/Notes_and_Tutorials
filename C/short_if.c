#include <stdio.h>
int main(){
    int m1,m2,m3;
    printf("enter your grades\n");
    scanf("%d %d %d", &m1 , &m2,&m3);
    m1 >= 40 ? m2 >= 40 ? m3 >= 40 ? printf("3") : printf("2") :printf("1") : printf("failed");
    return 0;
}