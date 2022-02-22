#include <stdio.h>

int main()
{
	int x, y;

	printf("enter x: ");
	scanf("%d", &x);

	printf("enter y: ");
	scanf("%d", &y);

	printf("\n%d^%d = %.f", x, y, pow(x,y));
	printf("\n%d^(1/2) = %f", x, sqrt(x));
	printf("\nlog%d = %f", x, log(x));

    return 0;
}