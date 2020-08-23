
//01.a
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define TSIZE 45 

struct film 
{
	char title[TSIZE];
	int rating;
	struct film *next;
	struct film *pre;
};

char *s_gets(char * st, int n)
{
	char *ret_val = NULL;
	char *find = NULL;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

int main()
{
	struct film *head = NULL;
	struct film *prev = NULL, *current = NULL;
	char input[TSIZE];

	puts("Enter first movie title : ");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *) malloc(sizeof(struct film));
		if (head == NULL)
		{
			head = current;
			head->pre = NULL;
		}
		else
		{
			prev->next = current;
			current->pre = prev;
		}
		current->next = NULL;
		strcpy_s(current->title, TSIZE, input);
		puts("Enter your rating <0-10>: ");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop): ");
		prev = current;
	}
	if (head == NULL)
		puts("No data entered.");
	else
		puts("Here is the movie list : ");
	current = head;
	while (current != NULL)
	{
		printf("Movie : %s Rating : %d\n", current->title, current->rating);
		prev = current;
		current = current->next;
	}
	if (head != NULL)
	{
		puts("\nHere is the list in reverse order : ");
		current = prev;
		while (current != NULL)
		{
			printf("Movie : %s Rating : %d\n", current->title, current->rating);
			current = current->pre;
		}
	}
	puts("Bye!");

	system("pause");
	return 0;
}

//*******************************************************************************************

//01.b
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TSIZE 45 

struct film 
{	
	char title[TSIZE];
	int rating;
	struct film * next; 
};

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

show(const struct film * pf)
{
	if (pf->next != NULL)
		show(pf->next);
	printf("Movie : %s Rating : %d\n", pf->title, pf->rating);
}

int main()
{
	struct film * head = NULL;
	struct film * prev = NULL, *current = NULL;
	char input[TSIZE];

	puts("Enter first movie title : ");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *) malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else 
			prev->next = current;
		current->next = NULL;
		strcpy_s(current->title, TSIZE, input);
		puts("Enter your rating <0-10>: ");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop): ");
		prev = current;
	}
	if (head == NULL)
		puts("No data entered.");
	else
		puts("Here is the movie list : ");
	current = head;
	while (current != NULL)
	{
		printf("Movie: %s Rating: %d\n", current->title, current->rating);
		current = current->next;
	}
	if (head != NULL)
	{
		puts("\nHere is the list in reverse order : ");
		show(head);
	}
	puts("Bye!");

	system("pause");
	return 0;
}

//*******************************************************************************************