#include <stdio.h>
#include <time.h>

/**
 * @brief delays the program for a given amount of time in milliseconds
 * 
 * @param milliseconds 
 */
void delay(unsigned milliseconds)
{
    clock_t start_time = clock();
    // loop until date exceeds called time + milliseconds
    // therefore delay is milliseconds
    while (clock() < start_time + milliseconds);
}

int main()
{
    time_t t;
    time(&t);
    printf("%s\n", ctime(&t)); // ctime() returns a string of the current time and date.
    delay(1000);
    time(&t);
    printf("%s\n", ctime(&t)); // day of week, month, day of month, hh:mm:ss yyyy

    return 0;
}
