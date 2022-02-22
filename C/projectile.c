#include <stdio.h>
#include <math.h>

#define ACCELERATION 9.81

float sinf (float, int);
float cosf (float, int);

int main()
{
    int angle;
    float velocity, time;

    printf("Enter the initial velocity(m/s): ");
    scanf("%f",&velocity);

    printf("Enter the projectile angle: ");
    scanf("%d",&angle);

    time = sinf(velocity, angle)/ACCELERATION;

    printf("\nRange: %f meter", 2*time * cosf (velocity, angle));
    printf("\nMax height: %f meter", time * sinf (velocity, angle)/2);
    printf("\nFlight time: %f second", 2*time);
}

float sinf (float value, int angle)
{
    return value * sin(angle * M_PI/180);
}

float cosf (float value, int angle)
{
    return value * cos(angle * M_PI/180);
}