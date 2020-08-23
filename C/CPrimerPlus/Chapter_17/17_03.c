
//list.h
//*******************************************************************************************

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

#define TSIZE 45 
#define MAXSIZE 100

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
	Item entries[MAXSIZE];
	int items;
} List;

InitializeList(List * plist);
bool ListIsEmpty(const List * plist);
bool ListIsFull(const List * plist);
unsigned int ListItemCount(const List * plist);
bool AddItem(Item item, List * plist);
Traverse(const List * plist, void(*pfun)(Item item));
EmptyTheList(List * plist);
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
	printf("Movie : %s Rating : %d\n", item.title,
		item.rating);
}

char * s_gets(char * st, int n)
{
	char * ret_val = NULL;
	char * find = NULL;

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
		fprintf(stderr, "No memory available! Bye!\n");
		exit(1);
	}
	puts("Enter first movie title : ");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>: ");
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
		puts("Enter next movie title (empty line to stop): ");
	}
	if (ListIsEmpty(&movies))
		printf("No data entered.\n");
	else
	{
		printf("Here is the movie list : \n");
		Traverse(&movies, showmovies);
	}
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

InitializeList(List * plist)
{
	plist->items = 0;
}

bool ListIsEmpty(const List * plist)
{
	if (plist->items == 0)
		return true;
	else
		return false;
}

bool ListIsFull(const List * plist)
{
	if (plist->items == MAXSIZE)
		return true;
	else
		return false;
}

unsigned int ListItemCount(const List * plist)
{
	return plist->items;
}

bool AddItem(Item item, List * plist)
{
	if (plist->items == MAXSIZE)
		return false;
	else
	{
		plist->entries[plist->items++] = item;
		return true;
	}
}

Traverse(const List * plist, void(*pfun)(Item item))
{
	int i;
	for (i = 0; i < plist->items; i++)
		(*pfun)(plist->entries[i]); 
}

EmptyTheList(List * plist)
{
	plist->items = 0;
}

//*******************************************************************************************