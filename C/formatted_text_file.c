#include <stdio.h>
int main(void) {
    
    char *parameterFileName= "C:\\Users\\faruk\\Desktop\\deneme.txt";
    char *resultFileName = "C:\\Users\\faruk\\Desktop\\deneme2.txt";
    
    FILE* parameterFile = NULL;
    parameterFile = fopen(parameterFileName, "r");
    if(parameterFile == NULL)
    {
        printf("The file not found!\n");
        return 0;
    }
    
    printf("The file named %s, was found.", parameterFileName);

    int num1, num2;
    char operation;    
    fscanf(parameterFile, "%d %c %d", &num1, &operation, &num2);
    
    FILE* resultFile = NULL;
    if((resultFile = fopen(resultFileName, "w")) != NULL)
    {
        int result = 0;
        switch(operation){
            case '+':
                result = num1 + num2; 
                break;
            case '-':
                result = num1 - num2;
                break;
            case 'x':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            case '%':
                result = num1 % num2;
                break;                  
        }                
        
        fprintf(resultFile, "The result = %d %c %d = %d", num1, operation, num2, result);        
        printf("\nThe result was printed on the file named %s\n", resultFileName);
    }

    fclose(parameterFile);
    fclose(resultFile);
    
    return 0;
}