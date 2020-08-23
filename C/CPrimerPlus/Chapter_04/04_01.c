#include <stdio.h>
#include <stdlib.h>

int main()
{
	char firstname[20] = "\0", lastname[20] = "\0";

	printf("Input your first name : ");
	scanf("%s", firstname, 20);
	printf("Input your last name : ");
	scanf("%s", lastname, 20);
	printf("%s %s\n", firstname, lastname);

	system("pause");
	return 0;
}