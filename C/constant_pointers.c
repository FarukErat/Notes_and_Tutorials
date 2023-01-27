#include <stdio.h>

int main()
{
    // char str1[]; //! incomplete type is not allowedC/C++(70) size must be specified
    char str2[10];            // constant pointer pointing to a fixed memory that can store 10 characters
    char str3[10] = "Cengiz"; // constant pointer pointing to a memory that stores string "Cengiz"
    char *str4;               // not constant pointer
    char *str5 = "Cengiz";    // totally same as str3
    char str6[] = "Cengiz";   // same as str3 but not constant pointer

    return 0;
}
