#include <stdio.h>
#include <stdlib.h>

copy_arr(int copy_num[], int num[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		copy_num[i] = num[i];
}

show_arr(int ar[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", ar[i]);
	putchar('\n');
}

int main()
{
	int num[7] = { 1,2,3,4,5,6,7 };
	int copy_num[3] = {0};

	show_arr(num, 7);
	copy_arr(copy_num, num + 2, 3);
	show_arr(copy_num, 3);

	system("pause");
	return 0;
}