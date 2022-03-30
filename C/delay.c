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
    while (clock() < time_end);
}

int main()
{
    time_t t;                  // time_t is a data type for time
    time(&t);                  // time() returns the current time in seconds since the Epoch
    printf("%s\n", ctime(&t)); // ctime() returns a string of the current time and date.
    delay(1000);               // delays the program for 1 second
    time(&t);                  // get the current time
    printf("%s\n", ctime(&t)); // day of week, month, day of month, hh:mm:ss yyyy

    return 0;
}
