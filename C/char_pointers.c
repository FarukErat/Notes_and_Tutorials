#include <stdio.h>

void myPrint(char *str)
{
    printf("%d %s\n", str, str);
}

int main()
{
    char *name, *temp;     // they shouldn't be used without initialization or memory allocation
    char name2[10];        // acts like constant pointer since it must obey its fixed memory that is allocated
    char *name3 = "Ahmet"; // this one is not constant
    myPrint(name);         // 4194432 PE
    putchar('\n');

    name = "Tom";  // allocates memory for string and 'name' points to it
    myPrint(name); // 4218955 Tom
    putchar('\n');

    temp = name;
    myPrint(name); // 4218955 Tom
    myPrint(temp); // 4218955 Tom
    putchar('\n');

    temp = "John";
    myPrint(name); // 4218955 Tom
    myPrint(temp); // 4218959 John
    putchar('\n');

    temp = name;
    myPrint(name); // 4218955 Tom
    myPrint(temp); // 4218955 Tom
    putchar('\n');

    return 0;
}
