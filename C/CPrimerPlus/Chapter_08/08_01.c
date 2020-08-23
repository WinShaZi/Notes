#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	char ch = '\0';

	while ((ch = getchar()) != EOF)
		i++;
	printf("%d\n", i);

	system("pause");
	return 0;
}