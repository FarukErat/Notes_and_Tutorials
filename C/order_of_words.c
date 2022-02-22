#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int j = 0;
    int k = 0;
    int letter;
    int word;
    int textLen;

    char text[801];
    char words[41][21];

    printf("enter the text\n");
    gets(text);
    textLen = strlen(text);

    for(i = 0; i < textLen; i++)
    {
        if(text[i] != 32)
        {
          words[j][k] = text[i];

          k++;
        }

        else if(text[i+1] != 32)
        {
            k = 0;

            j++;
        }
    }

    printf("\nenter the order of the word you want ");
    scanf("%d",&word);

    puts("");

    printf("%s",words[word-1]);

    return 0;
}