#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char ch = '\0';
	int i = 0, j = 0;

	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			i++;
		else if (islower(ch))
			j++;
	}
	printf("Majuscule have %d\nMinuscule have %d.\n", i, j);

	system("pause");
	return 0;
}