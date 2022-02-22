#include <stdio.h>
#include <string.h>

int main()
{
	int count = 0;

	char *ptr;
	char text[1001];
	char target[21];

	puts("enter the whole text");
	gets(text);

	puts("\nenter the text you want to search for");
	gets(target);

	ptr = strstr(text, target);

	while(ptr != NULL)
	{
		count++;
		ptr++;
		ptr = strstr(ptr, target);
	}

	printf("\nthere are %d of %s in the text", count, target);

    return 0;
}