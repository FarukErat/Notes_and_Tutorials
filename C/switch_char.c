#include <stdio.h>
int main(){

	char x;

	printf("the first letter of the day: ");
	scanf("%s",&x);

	switch (x)
	{
		case 'm': printf("monday");
		break;
	
		case 't': printf("tuesday, thursday");
		break;

		case 'w': printf("wednesday");
		break;

		case 'f': printf("friday");
		break;

		case 's': printf("saturday, sunday");
		break;

		default: printf("you entered wrongly");
	}

	return 0;
}