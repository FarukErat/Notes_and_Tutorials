#include <stdio.h>

typedef enum days
{
    MON = 1, // to start index from 1, otherwise, 0
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
} Days;

int main()
{
    Days day;
    const char *dayName[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
                             "Saturday", "Sunday"};
    for (day = MON; day <= SUN; day++)
    {
        printf("%d%11s\n", day, dayName[day]);
    }

    return 0;
}
