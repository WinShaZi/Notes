#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

int main()
{
	int word = 0;
	int upper = 0;
	int lower = 0;
	int chara = 0;
	int num = 0;
	int i = 0;
	char ch = '\0';

	printf("Input a character string : ");
	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			upper++;
		else if (islower(ch))
			lower++;
		else if (ispunct(ch))
			chara++;
		else if (isdigit(ch))
			num++;
		if (!isalpha(ch) && !i)
		{
			i = 1;
			word++;
		}
		if (isalpha(ch) && i)
			i = 0;
	}
	printf("Words     : %d\n", word);
	printf("Majuscule : %d\n", upper);
	printf("Minuscule : %d\n", lower);
	printf("Character : %d\n", chara);
	printf("Number    : %d\n", num);

	system("pause");
	return 0;
}