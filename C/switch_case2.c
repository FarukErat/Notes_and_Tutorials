#include <stdio.h>

int main()
{
	int number;

	printf("enter a number between 1 and 10: ");
	scanf("%d",&number);

	switch (number)
	{
		case 1:puts("1");
		case 2:puts("2"); break;
		case 3:puts("3"); break;
		case 4:puts("4");
		case 5:puts("5");
		case 6:puts("6"); 
		case 7:puts("7"); break;
		case 8:puts("8");
		case 9:puts("9"); break;
		case 10:puts("10");

		default: printf("you entered wrongly");
	}
	
	return 0;
}