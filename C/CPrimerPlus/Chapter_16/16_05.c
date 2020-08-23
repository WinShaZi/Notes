#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int num;
} st;

void fill(st choose[], int n)
{
	for (int i = 0; i < n; i++)
		choose[i].num = i + 1;
}

void clean()
{
	while (getchar() != '\n')
		continue;
}

int main()
{
	st *choose = NULL;
	int number = 0;
	int people = 0;

	printf("Input the number of participants : ");
	while (scanf("%d", &people) != 0 && people > 0)
	{
		clean();
		choose = (st*)malloc(people * sizeof(st));
		fill(choose, people);
		srand((unsigned int)time(NULL));
		printf("Input number of people : ");
		while (scanf("%d", &number) != 0 && number > 0)
		{
			clean();
			if (number > people)
			{
				printf("Input number of people selected : ");
				continue;
			}

			int a = 0, b = 0;

			for (int i = 0; i < number; i++)
			{
				a = rand() % people + 1;
				if (a == b)
				{
					i--;
					continue;
				}
				printf("%d ", a);
				if (i % 8 == 7)
					putchar('\n');
				b = a;
			}
			printf("\nInput number of people selected : ");
		}
		clean();
		printf("Input the number of participants : ");
	}

	system("pause");
	return 0;
}