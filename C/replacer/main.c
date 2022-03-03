#include <stdio.h>
#include "replacer.h"

int main()
{
    char text[] = "Hello World";
    char rep[] = "World";
    char with[] = "Universe";
    replacer(text, rep, with);
    printf("%s", text); // prints "Hello Universe"
    return 0;
}
