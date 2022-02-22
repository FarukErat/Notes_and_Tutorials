#include <stdio.h>
#include <string.h>
#include <conio.h>

#define TEXT_LENGTH 3001
#define CHANGED_LENGTH 201

int main()
{
    int i;
	int j;
	int count = 0;
	int textLen;
	int oldLen;
	int newLen;

	char repeat = 'r';
	char text[TEXT_LENGTH];
	char copyText[TEXT_LENGTH];
	char old[CHANGED_LENGTH];
	char New[CHANGED_LENGTH];

	printf("Enter the text you want to change\n");
	gets(text);
	textLen = strlen(text);

	while(repeat == 'r')
	{
		printf("\nEnter the text you want to replace\n");
		gets(old);
		oldLen = strlen(old);

		printf("\nEnter the text you want a text to be replaced with\n");
		gets(New);
		newLen = strlen(New);

		strcpy(copyText,text);

		for(i = 0; i < textLen; i++)
		{
			if(text[i] == old[0])
			{
				for(j = 0; j < oldLen; j++)
				{
					if(text[i + j] == old[j])
					{
						count++;
					}
				}

				if(count == oldLen)
				{
					for(j = 0; j < newLen; j++)
					{
						text[i + j] = New[j];
					}

					if(newLen != oldLen)
					{
						textLen += newLen - oldLen;

						for(j = 0; j < textLen - i - newLen + 1; j++)
						{
							text[i + newLen + j] = copyText[i + oldLen + j];
						}
					}

					strcpy(copyText,text);

					i += newLen - 1;
				}

				count = 0;
			}
		}

		printf("\nThe new text:\n%s",text);

		printf("\n\nPress r to repeat ");

		repeat = getch();

		puts("");

		}

    return 0;
}