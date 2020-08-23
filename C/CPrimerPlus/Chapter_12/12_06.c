#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void number(int *num, int *count)
{
	int n = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	int f = 0, g = 0, h = 0, i = 0, j = 0;

	for (n = 0; n < SIZE; n++)
	{
		if (num[n] == 1)
		{
			a++;
			count[0] = a;
		}
		if (num[n] == 2)
		{
			b++;
			count[1] = b;
		}
		if (num[n] == 3)
		{
			c++;
			count[2] = c;
		}
		if (num[n] == 4)
		{
			d++;
			count[3] = d;
		}
		if (num[n] == 5)
		{
			e++;
			count[4] = e;
		}
		if (num[n] == 6)
		{
			f++;
			count[5] = f;
		}
		if (num[n] == 7)
		{
			g++;
			count[6] = g;
		}
		if (num[n] == 8)
		{
			h++;
			count[7] = h;
		}
		if (num[n] == 9)
		{
			i++;
			count[8] = i;
		}
		if (num[n] == 10)
		{
			j++;
			count[9] = i;
		}
	}
}

int main()
{
	int n = 0;
	int num[SIZE] = {0};
	int count[SIZE] = {0};
	int x = 0, y = 0;

	printf("(1)  (2)  (3)  (4)  (5)  (6)  (7)  (8)  (9)  (10)\n\n");
	for (x = 0; x < 10; x++)
	{
		srand(x);
		for (y = 0; y < SIZE; y++)
			num[y] = rand() % 10 + 1;
		number(num, count);

		printf(" ");
		for (n = 0; n < 10; n++)
			printf("%-5d", count[n]);
		puts("\n");
	}

	system("pause");
	return 0;
}