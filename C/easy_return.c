#include <stdio.h>

double min(double, double);

int main(void)
{
    double x, y;

    printf("enter two numbers (q to quit)\n");

    while (scanf("%lf %lf",&x, &y) == 2)
    {
        printf("the smaller number is %f\n",min(x, y));
    }

    printf("Bye!");

    return 0;
}

double min(double a, double b)
{
    return a < b ? a : b;
}