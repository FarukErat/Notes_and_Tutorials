// about ways to assign values to a structure

#include <stdio.h>

typedef struct mystruct
{
    int a;
    int b;
    char c;
} MyStruct;

int main()
{
    MyStruct mystruct1;
    mystruct1.a = 1;
    mystruct1.b = 2;
    mystruct1.c = 'a';

    MyStruct mystruct2;
    // mystruct2 = {1, 2, 'a'}; // invalid syntax
    mystruct2 = (MyStruct){2, 4, 'b'}; // type cast

    MyStruct mystruct3 = {3, 6, 'c'};

    return 0;
}
