#include <iostream>
#include <ctime>

//! ///////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#include <windows.h>
inline void delay(unsigned long ms)
{
    Sleep(ms);
}

#else /* presume POSIX */
#include <unistd.h>
inline void delay(unsigned long ms)
{
    usleep(ms);
}
#endif
//! ///////////////////////////////////////////////////////////////////////////////////////////////////////

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
