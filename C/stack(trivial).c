#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void push(int);
int pop();
void print();
void menu();

int *bottom, *top;
int stack[SIZE];

int main()
{
	int choice;

	bottom = stack;
	top = stack;

	while(1)
	{
		menu();

		printf("Enter your choice: ");
		scanf("%d",&choice);
		int value;
		switch (choice)
		{
			case 0:
			printf("The program has ended.");
			exit(EXIT_SUCCESS);
			break;

			case 1:
			printf("Enter the value to be added: ");
			scanf("%d",&value);
			push(value);
			break;

			case 2:
			value = pop();
			printf("The value obtained from tha stack: %d",value);
			break;

			case 3:
			print();
			break;

			default:
			printf("Invalid value!\nPlease enter a valid value.");
			break;
		}
	}
	return 0;
}

void push(int i)
{
	if(top + 1 == (bottom + SIZE))
	{
		printf("The stack is full!\nYou cannot add more item.");
		exit(EXIT_FAILURE);
	}
	*top = i;
	top++;
}

int pop()
{
	if(top == bottom)
	{
		printf("The stack is empty!");
		exit(EXIT_FAILURE);
	}
	top--;
	int value = *top;
	return value;
}

void print()
{
	printf("\n[BOTTOM]\n");
	int* temp = stack;
	while(temp < top)
	{
		printf("%d\n",*temp);
		temp++;
	}
	printf("[TOP]");
}

void menu()
{
	printf("----------\n   MENU   \n----------\n");
	printf("1.ADD(push)\n2.OBTAIN(pop)\n3.PRINT\n0.EXIT\n");
}
