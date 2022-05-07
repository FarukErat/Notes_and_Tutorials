#include <stdio.h>
#include "replace.h"

int main()
{
    char *str = "Hello, World!";
    char *rep = "World";
    char *with = "Universe";
    char *result = str_replace(str, rep, with);
    printf("%s-\n", result);
    free(result);

    return 0;
}
