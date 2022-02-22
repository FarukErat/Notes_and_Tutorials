#include <stdio.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_NUMBER 100

int main(void) {
    
    char *fileName = "C:\\Users\\faruk\\Desktop\\deneme.txt";
    
    FILE* file = NULL;
    
    file = fopen(fileName, "r+");
    
    if(file == NULL)
    {
        printf("The file not found!\n");
        return 0;
    }
    
    printf("\nThe file is being read...\n");

    int i = 0;
    char wordArray[MAX_WORD_NUMBER][MAX_LINE_LENGTH];

    while(i < MAX_WORD_NUMBER && !feof(file))
    {
        fgets(wordArray[i], MAX_LINE_LENGTH, file);
        i++;
    }

    rewind(file);
    
    while(i >= 0)
    {
        fputs(wordArray[i], file);
        i--;
    }
        
    printf("\nThe file has been reversed.");
    fclose(file);
    return 0;
}