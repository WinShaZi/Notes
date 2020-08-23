#include <stdio.h>
#include <stdlib.h>

int main()
{
	float Mb = 0, MB = 0, second = 0;

	printf("Input your btroadband speed(Mb/s) : ");
	scanf("%f", &Mb);
	printf("Input your file size(MB) : ");
	scanf("%f", &MB);
	second = MB / (Mb / 8);
	printf("At %.2f megabits per second,a file of %.2f megabytes\n", Mb, MB);
	printf("downloads in %.2f second.\n", second);

	system("pause");
	return 0;
}