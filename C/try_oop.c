#include <stdio.h>

typedef struct person
{
    int age;
    char name[20];
}Person;

void init(Person* person)
{
    char unknown[8] = "unknown";
    person->age = 0;
    int size = sizeof(person->name);
    for (int i = 0; i < 8 && i < size; i++)
    {
        *(person->name + i) = *(unknown + i);
    }
}

int main ()
{
    Person mert;
    init(&mert);

    printf("%d\n",mert.age);
    printf("%s\n",mert.name);
    mert.age = 19;

    return 0;
}
