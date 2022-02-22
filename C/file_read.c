#include <stdio.h>

int main(void) {
    
    FILE* file = NULL;

    file = fopen("C:\\Users\\faruk\\Desktop\\Japenese.txt", "r");
    
    if(file == NULL)
    {
        printf("The file not found!\n");
    }

    else
    {
        printf("-------------\n");
        printf("File Contents\n");
        printf("-------------\n");
        
        int ch;

        while((ch = fgetc(file)) != EOF)
            putchar(ch);

        fclose(file);
    }

    return 0;
}