#include <stdio.h>
#include <stdlib.h>

void br();
void ic();

int main()
{
	br();
	putchar(',');
	ic();
	putchar('\n');
	ic();
	putchar(',');
	putchar('\n');
	br();
	putchar('\n');

	system("pause");
	return 0;
}

void br()
{
	printf("Brazil,russia");
}

void ic()
{
	printf("India,Chain");
}