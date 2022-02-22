#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    int i;
    int j;
    int numTarget;
    int count = 0;
    int textLen;
    int targetLen;

    char repeat = 'r';
    char text[3001];
    char target[51];

    printf("enter the text\n");
    gets(text);
    textLen = strlen(text);

    while(repeat == 'r')
    {
        numTarget = 0;

        printf("\nenter the text you want to know how many of it is in the text\n");
        gets(target);
        targetLen = strlen(target);

        for(i = 0; i < textLen; i++)
        {
            if(text[i] == target[0])
            {
                for(j = 0; j < targetLen; j++)
                {
                	if(text[i + j] == target[j])
                	{
                		count++;
					}
				}

                if(count == targetLen)
                {
                	numTarget++;
				}

                count = 0;
            }
        }

        printf("\nthere are %d of %s in the text",numTarget, target);

        printf("\n\npress r to repeat ");

        repeat = getch();

        puts("");
    }

    return 0;
}