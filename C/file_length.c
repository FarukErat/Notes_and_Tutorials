#include <stdio.h>

int main(void)
{
    char *fileName = "C:\\Users\\faruk\\Desktop\\dosya.txt";
    FILE* file = NULL;

    file = fopen(fileName, "r");

    if(file == NULL)
    {
        printf("The file not found!\n");
        return 0;
    }

    fseek(file, 0, SEEK_END);

    long int length = ftell(file);
    
    printf("The length of the file: %ld byte", length);
    
    fclose(file);
    
    return 0;
}