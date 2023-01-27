// demonstartion of padding in structures in 32-bit (4byte) mode

#include <stdio.h>

// #### #### #### (visual representation of free memory layout)

typedef struct
{
    char a; // a### #### ####
    int b;  // a### bbbb ####
    char c; // a### bbbb c###
} Struct1;

typedef struct
{
    char a; // a### #### ####
    char c; // ac## #### ####
    int b;  // ac## bbbb ####
} Struct2;

int main()
{
    printf("sizeof(Struct1) = %d bytes\n", sizeof(Struct1));
    printf("sizeof(Struct2) = %d bytes\n", sizeof(Struct2));

    return 0;
}