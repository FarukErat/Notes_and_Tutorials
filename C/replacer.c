#include <stdio.h>
#include <string.h>
#include <conio.h>

#define TEXT_LENGTH 3001
#define CHANGED_LENGTH 201

int main()
{
    int count = 0;
    int textLen;
    int oldLen;
    int newLen;

    char repeat = 'r';
    char text[TEXT_LENGTH];     // main text
    char copyText[TEXT_LENGTH]; // copy of main text to do operations on
    char rep[CHANGED_LENGTH];   // text to be replaced
    char with[CHANGED_LENGTH];  // text to replace old text with

    printf("Enter the text you want to change\n");
    gets(text);
    textLen = strlen(text);

    while (repeat == 'r')
    {
        printf("\nEnter the text you want to replace\n");
        gets(rep);
        oldLen = strlen(rep);
        printf("\nEnter the text you want a text to be replaced with\n");
        gets(with);
        newLen = strlen(with);
        strcpy(copyText, text);
        for (int i = 0; i < textLen; i++)
        {
            // check if the new text occur in the old text
            for (int j = 0; j < oldLen; j++)
            {
                if (text[i + j] == rep[j])
                {
                    count++;
                }
            }
            // if count matches the old text length then replace the old text with the new text
            if (count == oldLen)
            {
                // alter the occurence of the old text with the new text
                for (int j = 0; j < newLen; j++)
                {
                    text[i + j] = with[j];
                }
                // if the lengths do not match then shift the text accordingly
                if (newLen != oldLen)
                {
                    int diff = newLen - oldLen;
                    // increment the text length by the difference
                    textLen += diff;
                    // the shift will not be done before the occurence of the old text
                    // that is why (i + newLen) is subtracted from the text length
                    // to shift the string terminator, 1 is added
                    for (int j = 0; j < textLen - (i + newLen) + 1; j++)
                    {
                        // (i + newLen) is where the shift will start and j is to iterate through the text
                        // copyText is the string that remains unchanged from the previous operation
                        // the uncganged part starts at i + oldLen in the copyText
                        text[(i + newLen) + j] = copyText[(i + oldLen) + j];
                    }
                }
                strcpy(copyText, text);
                // iterate i to skip the replaced text
                // -1 to cancel the increment in the for loop
                i += newLen - 1;
            }
            // reset count
            count = 0;
        }
        printf("\nThe new text:\n%s", text);
        printf("\n\nPress r to repeat ");
        repeat = getch();
        puts("");
    }

    return 0;
}
