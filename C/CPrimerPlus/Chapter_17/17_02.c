
//list.h
//*******************************************************************************************

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

#define TSIZE 45

struct film 
{
	char title[TSIZE];
	int rating;
};

typedef struct film Item;

typedef struct node 
{
	Item item;
	struct node * next;
} Node;

typedef struct list 
{
	Node * head;
	Node * end;
} List;

InitializeList(List * plist);
bool ListIsEmpty(const List * plist);
bool ListIsFull(const List * plist);
unsigned int ListItemCount(const List * plist);
bool AddItem(Item item, List * plist);
Traverse(const List * plist, void(*pfun)(Item item));
EmptyTheList(List * plist);
ShowEnd(List * plist);
#endif

//*******************************************************************************************

//films3.c
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

showmovies(Item item)
{
	printf("Movies : %s Rating : %d\n", item.title, item.rating);
}

char *s_gets(char *st, int n)
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
	List movies;
	Item temp;

	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memeory available!Bye!\n");
		exit(1);
	}

	puts("Enter first movie title : ");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10> : ");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movie title(empty line to stop) : ");
	}

	if (ListIsEmpty(&movies))
		puts("No data entered.");
	else
	{
		puts("Here is the movie list : ");
		Traverse(&movies, showmovies);
	}
	puts("Last movie is : ");
	ShowEnd(&movies);
	printf("You entered %d movies.\n", ListItemCount(&movies));

	EmptyTheList(&movies);
	printf("Bye!\n");

	system("pause");
	return 0;
}

//*******************************************************************************************

//list.c
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}

InitializeList(List * plist)
{
	(*plist).head = NULL;
	(*plist).end = NULL;
}

bool ListIsEmpty(const List * plist)
{
	if ((*plist).head == NULL)
		return true;
	else
		return false;
}

bool ListIsFull(const List * plist)
{
	Node * pt = NULL;
	bool full = true;

	pt = (Node *)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	return full;
}

unsigned int ListItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = (*plist).head;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}

bool AddItem(Item item, List * plist)
{
	Node * pnew = NULL;
	Node * scan = (*plist).head;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;

	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL)
		(*plist).head = pnew;
	else
	{
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}
	(*plist).end = pnew;
	return true;
}

Traverse(const List * plist, void(*pfun)(Item item))
{
	Node * pnode = (*plist).head;
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

EmptyTheList(List * plist)
{
	Node * psave = NULL;
	while ((*plist).head != NULL)
	{
		psave = (*plist).head->next;
		free((*plist).head);
		(*plist).head = psave;
	}
}

ShowEnd(List * plist)
{
	printf("Movies : %s Rating : %d\n", (*plist).end->item.title, (*plist).end->item.rating);
}

//*******************************************************************************************