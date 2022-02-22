#include <stdio.h>

typedef union
{
	int numInt;
	float numFloat;
} Number;

int main()
{
	Number number;
	number.numInt = 0;
	printf("number.numInt : %d", number.numInt);
	printf("\nnumber.numFloat : %f", number.numFloat);

	number.numFloat = 3.14;
	printf("\nnumber.numInt : %d", number.numInt);
	printf("\nnumber.numFloat : %f", number.numFloat);

	return 0;
}