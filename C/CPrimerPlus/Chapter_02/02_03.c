#include <stdio.h>
#include <stdlib.h>

int main()
{
	int years_old = 0, live_days = 0;

	printf("Input your age : ");
	scanf("%d", &years_old);
	live_days = years_old * 365;
	printf("The das you live for are : %d\n", live_days);

	system("pause");
	return 0;
}