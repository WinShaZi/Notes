#include <stdio.h>
#include <stdlib.h>

#define SIZE 2

void a_a(char ch)
{
	printf("%c\n", ch);
}

void b_b(char ch)
{
	printf("%c\n", ch + 1);
}

int main()
{
	void (*fp[SIZE])(char ch) = {a_a, b_b};
	char ch = 0;

	printf("Input a letter : ");
	scanf("%c", &ch, 1);
	if (ch == 'a')
		(*fp[0])(ch);
	else if (ch == 'b')
		(*fp[1])(ch);
	else
		printf("Done.\n");

	system("pause");
	return 0;
}