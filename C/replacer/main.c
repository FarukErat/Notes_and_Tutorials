#include <stdio.h>
#include "replacer.h"

int main()
{
    char text[] = "Hello World";
    char rep[] = "World";
    char with[] = "Universe";
    replacer(text, rep, with);
    // "!" is to see if there is any character in the end of the string
    // to make sure the code runs properly
    printf("%s!", text); // prints "Hello Universe!"
    return 0;
}
