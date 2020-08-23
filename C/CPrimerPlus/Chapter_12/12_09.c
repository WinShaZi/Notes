#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n = 0;

	printf("How many words do you wish wo enter ? \n");
	while (!scanf("%d", &n) || n <= 0)
		continue;
	printf("Enter %d words now : \n", n);
	char **letter = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; ++i)
	{
		char str[100] = "\0";

		scanf("%s", str, 100);
		int m = (int)strlen(str) + 1;
		char *st = (char*)malloc(m * sizeof(char));
		for (int i = 0; i < m; i++)
			st[i] = str[i];
		letter[i] = st;
	}
	for (int i = 0; i < n; i++)
		puts(letter[i]);

	system("pause");
	return 0;
}