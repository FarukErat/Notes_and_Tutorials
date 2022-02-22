#include <stdio.h>

#define pi 3.14

int main()
{
	int r;
    float c;

    printf("cember cevresi hesaplama");
    printf("\ncap degerini girin\n");

    scanf("%d",&c);

    c=2*pi*r;

    printf("cevre: %.2f",c);

    const float euler = 2.71828;
    //euler number cannot be changed as it is declared by const
    //the same for pi due to define

    return 0;
}