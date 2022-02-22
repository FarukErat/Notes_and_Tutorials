#include <stdio.h>
int main(void) {
    
    char resourceFileName[40];
    char targetFileName[40];
    
    printf("Enter the resource file name: ");
    scanf("%s", resourceFileName);
    
    
    FILE* resourceFile = NULL;
    resourceFile = fopen(resourceFileName, "r");
    if(resourceFile == NULL)
    {
        printf("The resource file not found!\n");
        return 0;
    }
    
    printf("Enter the name of the new file: ");
    scanf("%s", targetFileName);
    
    
    FILE* targetFile = NULL;
    if((targetFile = fopen(targetFileName, "w")) != NULL)
    {
        int ch;
        while((ch = fgetc(resourceFile)) != EOF)
            fputc(ch, targetFile);

        printf("\nCopying has been done.\n");
    }
    
    else
        printf("\nAn error occured while creating the file named %s ", targetFileName);

    fclose(resourceFile);
    fclose(targetFile);
    
    return 0;
}