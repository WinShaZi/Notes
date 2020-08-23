#include <stdio.h>
#include <stdlib.h>

int i = 0;

int number()
{
	return i++;
}

int main()
{
	int n = 0;

	if (scanf("%d", &n) && n >= 0)
	{
		for (; n > 0; n--)
			number();
		printf("%d\n", i);
	}

	system("pause");
	return 0;
}