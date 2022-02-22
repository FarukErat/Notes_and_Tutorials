#include <stdio.h>

typedef struct
{
	//1byte = 4bit
	unsigned int day :5; // 31, 2^5=32
	unsigned int month :4; //12, 2^4=16
	unsigned int year :11; //2021, 2^11=2048
} BirthDate;

int main()
{
	int dateDay, dateMonth, dateYear;
	
	printf("Enter your birthday in DD/MM/YYYY format: ");
	
	scanf("%d/%d/%d", &dateDay, &dateMonth, &dateYear);
	
	BirthDate birthDate;
	
	birthDate.day = dateDay;
	birthDate.month = dateMonth;
	birthDate.year = dateYear;
	
	printf("The birth day:   %d\n", birthDate.day);
	printf("The birth month: %d\n", birthDate.month);
	printf("The birth year:  %d", birthDate.year);
	
	return 0;
}