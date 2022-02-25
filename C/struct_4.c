#include <stdio.h>

struct student
{
    int age;
    int grade;
    char name[40];
};

int main()
{
    struct student s1 = {.grade = 9, .age = 19, .name = "John Birghimer"};

    printf("Name: %s, Age: %d, Grade: %d\n", s1.name, s1.age, s1.grade);

    return 0;
}
