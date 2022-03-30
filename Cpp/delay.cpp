#include <iostream>
#include <ctime>

/**
 * @brief delays the program for a given amount of time in milliseconds
 *
 * @param milliseconds
 */
void delay(unsigned milliseconds)
{
    clock_t time_end;
    time_end = clock() + milliseconds;
    while (clock() < time_end); // wait until time_end
}

int main()
{
    // test the delay function
    time_t t;                                                              // time_t is a type for time in seconds since the Epoch
    time(&t);                                                              // get the current time
    std::cout << "The local date and time is: " << ctime(&t) << std::endl; // print the time
    delay(1000);                                                           // delay for 1 second
    time(&t);                                                              // get the current time
    std::cout << "The local date and time is: " << ctime(&t) << std::endl; // print the time
    return 0;
}
