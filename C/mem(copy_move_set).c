#include <stdio.h>
#include <string.h>

int main()
{
	char text1[41] = "zzzzzyyyyyxxxxxvvvvv";
	char text2[41] = "zzzzzyyyyyxxxxxvvvvv";
	char buffer1[41] = "aaaaabbbbbcccccddddd";
	char buffer2[41] = "aaaaabbbbbcccccddddd";

	memcpy(buffer1 + 5, text1, 10); //copy the first 10 characters of text1 to buffer + 5
	printf("the text after memcpy:\n%s", buffer1);

	memmove(buffer2 + 10, text2 + 15, 5); //copy the first 5 characters of text2 + 15 to buffer2 + 10
	printf("\n\nthe text after memmove:\n%s", buffer2); //which is safer than memcpy

	memset(text1 + 10, '*', 5); //type * to the first 5 characters of text + 10
	printf("\n\nthe text after memset:\n%s", text1);

    return 0;
}