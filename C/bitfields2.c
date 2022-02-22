#include <stdio.h>

typedef struct
{
	unsigned int number :2; //2^2
} TillFour;

int main()
{
	TillFour temp;
	
	int i;
	
	for(i = 0; i < 8; i++)
	{
		temp.number = i;
		
		printf("%d\n", temp.number);
	}
	
	return 0;
}