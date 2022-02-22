#include <stdio.h>

int main()
{
	typedef int integer;
	typedef char character;
	
	integer num = 5;
	character text[50] = {"sweet home alabama"};
	
	printf("%s %d",text, num);
	
	return 0;
}