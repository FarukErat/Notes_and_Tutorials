#include <stdio.h>
#include <string.h>

int main()
{
	char text[21] = "aaaaabbbbbcccccddddd";

	char textForStrcpy[41] = "abcdefghij";
	strcpy(textForStrcpy + 3, text + 5); //change the rest of textForStrcpy + 3 with text + 5
	printf("the text after strcpy:\n%s", textForStrcpy); //abcbbbbbcccccddddd

	char textForStrcat[41] = "0123456789";
	strcat(textForStrcat, text + 10); //add the whole of text + 10 to the end of the textForStrcat
	printf("\n\nthe text after strcat:\n%s", textForStrcat); //0123456789cccccddddd

	char textForStrNcpy[41] = "9876543210";
	strncpy(textForStrNcpy, text + 4, 3); //change the first 3 characters of textForStrcpy with text + 4
	printf("\n\nthe text after strncpy:\n%s", textForStrNcpy); //abb6543210

	char textForStrNcat[41] = "jihgfedcba";
	strncat(textForStrNcat, text + 7, 2); //add the first 2 characters of text + 7 to the end of the text
	printf("\n\nthe text after strncat:\n%s", textForStrNcat); //jihgfedcbabb

    return 0;
}