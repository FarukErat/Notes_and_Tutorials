#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>  // printf()
#include <stdlib.h> // srand(), rand()
#include <time.h>   // time()

int random(int min, int max)
{
    if (min > max)
    {
        printf("Error: min > max\n");
        return 0;
    }
    return rand() % (max - min + 1) + min;
}

#endif // RANDOM_H
