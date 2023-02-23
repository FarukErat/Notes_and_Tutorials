#include <stdio.h>
#include <math.h>

/**
 * @brief Calculate and return the permutation of n and r
 *
 * @param n
 * @param r
 * @return int
 */
int permutation(int n, int r)
{
    int i, result = 1;
    for (i = n; i > n - r; i--)
    {
        result *= i;
    }
    return result;
}

/**
 * @brief Calculate and return the combination of n and r
 *
 * @param n
 * @param r
 * @return int
 */
int combination(int n, int r)
{
    return permutation(n, r) / permutation(r, r);
}

/**
 * @brief Calculate and print the binomial distribution
 *
 * @param x
 * @param y
 * @param power
 */
void binomial_distribution(int x, int y, int power)
{
    int isFirstTerm = 1; // first term does not have a sign other than its own coefficient
    int c;               // coefficient
    for (int i = 0; i <= power; i++)
    {
        c = combination(power, i) * (int)(pow(x, power - i) * pow(y, i));
        if (!isFirstTerm)
        {
            if (c > 0)
            {
                printf(" + ");
            }
            else
            {
                printf(" - ");
                c = -c;
            }
        }
        isFirstTerm = 0;
        if (c != 1)
        {
            printf("%d", c);
        }
        if (power - i != 0)
        {
            if (power - i != 1)
            {
                printf("x^%d", power - i);
            }
            else
            {
                printf("x");
            }
        }
        if (i != 0)
        {
            if (i != 1)
            {
                printf("y^%d", i);
            }
            else
            {
                printf("y");
            }
        }
    }
}

int main()
{
    int x, y, power;
    printf("Enter the value of x    : ");
    scanf("%d", &x);
    printf("Enter the value of y    : ");
    scanf("%d", &y);
    printf("Enter the value of power: ");
    scanf("%d", &power);
    binomial_distribution(x, y, power);
    return 0;
}

/*
Output:

Enter the value of x    : -2
Enter the value of y    : 2
Enter the value of power: 3
-8x^3 + 24x^2y - 24xy^2 + 8y^3

*/
