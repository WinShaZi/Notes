
//pe12-8.c
//*******************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *make_array(int elem, int val)
{
	int *pp = NULL;

	pp = (int *)malloc(elem * sizeof(int));

	for (int i = 0; i < elem; i++)
		pp[i] = val++;

	return pp;
}

void show_array(const int ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%-5d", ar[i]);
		if ((i + 1) % 8 == 0)
			putchar('\n');
	}
	putchar('\n');
}

int main()
{
	int *pa = NULL;
	int size = 0;
	int value = 0;

	printf("Enter the number of elements : ");
	while (scanf("%d", &size) && size > 0)
	{
		printf("Enter the initialization value : ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (<1 to quit) : ");
	}
	printf("Done!\n");

	system("pause");
	return 0;
}

//*******************************************************************************************