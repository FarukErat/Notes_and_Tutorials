#include <stdio.h>

enum day
{
    monday = 1,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
};

int main()
{
    int counter = 1;

    switch (saturday)
    {
    case 1:
        counter++;
    case 2:
        counter++;
    case 3:
        counter++;
    case 4:
        counter++;
    case 5:
        printf("There are %d days until the weekend.\n", counter);
        break;
    case 6:
        counter++;
    case 7:
        printf("You have %d days to relax.\n", counter);
        break;
    default:
        printf("Invalid day.\n");
        break;
    }

    return 0;
}