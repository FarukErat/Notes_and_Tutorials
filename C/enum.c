#include <stdio.h>

enum days{monday, tuesday, wednesday, thursday, friday, saturday, sunday};

int main()
{
	enum days day;

	day = friday;

	printf("%d",day + 1);

	return 0;
}