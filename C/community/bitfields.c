#include <stdio.h>

typedef struct
{
    unsigned int day : 5;   // 31, 2^5=32
    unsigned int month : 4; // 12, 2^4=16
    unsigned int year : 11; //     2^11=2048
} BirthDate;

int main()
{
    int dateDay, dateMonth, dateYear;
    BirthDate birthDate;

    printf("Size of BirthDate: %d\n", sizeof(BirthDate));

    printf("Enter your birthday in DD/MM/YYYY format: ");
    scanf("%d%*c%d%*c%d", &dateDay, &dateMonth, &dateYear);

    birthDate.day = dateDay;
    birthDate.month = dateMonth;
    birthDate.year = dateYear;

    printf("The birth day:   %d\n", birthDate.day);
    printf("The birth month: %d\n", birthDate.month);
    printf("The birth year:  %d\n", birthDate.year);

    return 0;
}