#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int inarray(const int sorted[], int size, int val)
{
	int min = 0;
	int max = size - 1;
	int mid = 0;
	int found = 0;

	while (min < max)
	{
		mid = (min + max) / 2;
		if (val < sorted[mid])
			max = mid - 1;
		else if (val > sorted[mid])
			min = mid + 1;
		else
		{
			found = 1;
			break;
		}
	}
	if (sorted[min] == val)
		found = 1;

	return found;
}

int main()
{
	int nums[SIZE] = { 1, 20, 40, 41, 42, 43, 70, 88, 92, 109 };
	int num = 0;
	int found = 0;

	printf("Enter an integer to search for : ");
	while (scanf("%d", &num) == 1)
	{
		found = inarray(nums, SIZE, num);
		printf("%d %s in the array.\n", num, found ? "is" : "isn't");
		printf("Next value (q to quit): ");
	}
	printf("Bye.\n");

	system("pause");
	return 0;
}