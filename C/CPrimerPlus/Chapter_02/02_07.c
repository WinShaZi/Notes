#include <stdio.h>
#include <stdlib.h>

void smile();

int main()
{
	smile();
	smile();
	smile();
	putchar('\n');
	smile();
	smile();
	putchar('\n');
	smile();
	putchar('\n');

	system("pause");
	return 0;
}

void smile()
{
	printf("Smile!");
}