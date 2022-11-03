#include <stdio.h>
#include <time.h>

/**
 * @brief delays the program for a given amount of time in milliseconds
 *
 * @param milliseconds
 */
void delay(unsigned milliseconds)
{
    clock_t time_end = clock() + milliseconds;
    while (clock() < time_end)
        ;
}

int main()
{
    time_t t; // time_t is a data type for time
    clock_t start, finish;

    time(&t);                                            // time() alters the variable via its address to hold the current time in seconds since the Epoch
    printf("The local date and time is: %s", ctime(&t)); // ctime() returns the seconds since the Epoch as a string of the current time and date.

    start = clock(); // clock() returns the number of milliseconds elapsed since the program started
    delay(1750);     // delays the program for 1.750 second
    finish = clock();
    printf("Time elapsed: %d milliseconds\n", finish - start); // to be more precise, use milliseconds instead of seconds

    time(&t);                                            // get the current time
    printf("The local date and time is: %s", ctime(&t)); // day of week, month, day of month, hh:mm:ss yyyy

    /*
    The local date and time is: Thu Nov 03 17:31:52 2022
    Time elapsed: 1750 milliseconds
    The local date and time is: Thu Nov 03 17:31:54 2022
    */

    return 0;
}
