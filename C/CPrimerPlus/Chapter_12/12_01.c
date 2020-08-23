#include <stdio.h>
#include <stdlib.h>

int critic(int units)
{
	printf("No luck,my friend.Try again.\n");
	if (scanf("%d", &units) != 1)
		exit(0);

	return units;
}

int main()
{
	int units = 0;

	printf("How many pounds to a firkin of butter?\n");
	if (scanf("%d", &units) != 1)
		exit(0);
	while (critic(units) != 56)
		continue;
	printf("You must have looked it up!\n");

	system("pause");
	return 0;
}