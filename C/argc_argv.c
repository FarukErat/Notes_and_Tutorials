#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int sum;

	if(argc != 3)
	{
		puts("the number of the arguments must be 3");
		
		exit(1);
	}
	else
	{
		printf("the name of the program: %s\n", argv[0]);
		printf("the first argument: %s\n", argv[1]);
		printf("the second arfument: %s\n", argv[2]);
	}

	sum = atoi(argv[1]) + atoi(argv[2]);

	printf("the sum of these two numbers: %d", sum);

    return 0;
}