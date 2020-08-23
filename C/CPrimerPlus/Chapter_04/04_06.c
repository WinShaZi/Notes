#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char first[20] = "\0", last[20] = "\0";

	printf("Input yuor first name : ");
	scanf("%s", first, 20);
	printf("Input your last name : ");
	scanf("%s", last, 20);
	printf("%s %s\n", first, last);
	printf("%*d %*d\n", strlen(first), strlen(first), strlen(last), strlen(last));
	printf("%s %s\n", first, last);
	printf("%-*d %-*d\n", strlen(first), strlen(first), strlen(last), strlen(last));

	system("pause");
	return 0;
}