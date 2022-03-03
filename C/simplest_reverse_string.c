#include <stdio.h>

void reverse(char *arr)
{
    if (arr[0] != '\0')
    {
        reverse(arr + 1);
        // before printing, there is a recursive call to reverse
        // when it arr[0] == '\0', recursive call will stop
        // the last reverse function call will start printing
        // every function that are called prints the last character and then returns
        printf("%c", *arr);
    }
}

int main()
{
    // the text is written on the memory
    // arr holds the beginning of the text (the first character)
    // arr is rather a pointer to the first character, not an array
    // "[]" is just an operator to iterate the pointer and to imply that it is an pointer
    char arr[] = {"I am a student"};
    reverse(arr);

    return 0;
}
