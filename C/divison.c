#include <stdio.h>

void divison(int, int);

int main()
{
    int dividend, divisor;

    printf("input the dividend: ");
    scanf("%d",&dividend);

    printf("\ninput the divisor: ");
    scanf("%d",&divisor);

    divison(dividend, divisor);

    return 0;
}

void divison(int dividend, int divisor)
{
	int i;
    int remaining;
	int tempRemaining;
	int tempDivisor;

    remaining = tempRemaining = dividend % divisor;

    tempDivisor = divisor;

    for (i = 2; i <= tempRemaining; i++)
    {
        if ((remaining % i == 0) && (divisor % i == 0))
        {
            remaining /= i;
            divisor /= i;
            i--;
        }
    }

    printf("\nresult: %d",(dividend - tempRemaining)/tempDivisor);
    if(remaining!=0)
    printf(" + %d/%d",remaining, divisor);
}