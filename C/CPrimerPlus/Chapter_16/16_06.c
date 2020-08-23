#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM 40
#define SIZE 10
#define LEN 3

struct names
{
	char first[SIZE];
	char last[SIZE];
};

void fill(struct names staff[], int n)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < LEN; j++)
		{
			staff[i].first[j] = rand() % 26 + 'A';
			staff[i].last[j] = rand() % 26 + 'A';
		}
		staff[i].first[LEN] = '\0';
		staff[i].last[LEN] = '\0';
	}
}

void show(struct names staff[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s %s  ", staff[i].first, staff[i].last);
		if (i % 4 == 3)
			putchar('\n');
	}
}

int comp(const void* p1, const void* p2)
{
	const struct names* ps1 = (const struct names*)p1;
	const struct names* ps2 = (const struct names*)p2;
	int res;

	res = strcmp(ps1->last, ps2->last);
	if (res != 0)
		return res;
	else
		return strcmp(ps1->first, ps2->last);
}

int main()
{
	struct names staff[NUM];

	fill(staff, NUM);
	puts("Random list : ");
	show(staff, NUM);
	qsort(staff, NUM, sizeof(struct names), comp);
	puts("\nSorted list : ");
	show(staff, NUM);

	system("pause");
	return 0;
}