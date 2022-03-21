#include <stdio.h>
// #pragma pack(1) // 1 byte alignment

/*
 * Why padding?
 * When moving forward along the memory to read data, which is done word by word(4 bytes commonly),
 * some members of a struct may be between two words.
 * When we want to access only the members of a struct that are between two words,
 * we will need to read left and right words too, to get the data as a whole.
 *
 * Padding is a way to solve this problem.
 * Compiler will add padding bytes to the struct to make sure that the struct is word aligned.
 * Padding bytes are not stored in the struct, but are just there to make sure that the struct is word aligned.
 * Thus, we waste space, but we can access the data as a whole with less CPU cycle.
 *
 * It makes a lot sense to order the members of a struct in a way that makes the struct word aligned.
 * Or we can use the #pragma pack(1) directive to make the struct word aligned.
 */

typedef struct
{
    char a; // 1 byte
    char b; // 1 byte
    // two bytes of padding
    int c; // 4 bytes
} S1;

typedef struct
{
    char a; // 1 byte
    // 3 bytes of padding
    int b;  // 4 bytes
    char c; // 1 byte
    // there will be 3 bytes of padding here
} S2;

int main()
{
    S1 m;
    S2 n;
    printf("The size of the structure m is %d\n", sizeof(m));
    printf("m.a -> %d\t%d\n", &m.a, &m.a + 1);
    printf("m.b -> %d\t%d\n", &m.b, &m.b + 1);
    printf("m.c -> %d\t%d\n", &m.c, &m.c + 1);
    printf("The size of the structure n is %d\n", sizeof(n));
    printf("n.a -> %d\t%d\n", &n.a, &n.a + 1);
    printf("n.b -> %d\t%d\n", &n.b, &n.b + 1);
    printf("n.c -> %d\t%d\n", &n.c, &n.c + 1);
    return 0;
}