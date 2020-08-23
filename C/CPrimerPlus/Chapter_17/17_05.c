
//list.h
//*******************************************************************************************

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#define MAXSTACK 100

typedef char Item;

typedef struct stack
{
	Item items[MAXSTACK];
	int top;
} Stack;

void InitializeStack(Stack * ps);
bool FullStack(const Stack * ps);
bool EmptyStack(const Stack * ps);
bool Push(Item item, Stack * ps);
bool Pop(Item *pitem, Stack * ps);

#endif

//*******************************************************************************************

//list_a.c
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define SLEN 81

char * s_gets(char * st, int n)
{
	char * ret_val = NULL;
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
	Stack stch;
	char temp[SLEN] = "\0";
	int i = 0;
	char ch = '\0';

	InitializeStack(&stch);
	printf("Enter a line (an empty line to quit): \n");
	while (s_gets(temp, SLEN) && temp[0] != '\0')
	{
		i = 0;
		while (temp[i] != '\0' && !FullStack(&stch))
			Push(temp[i++], &stch);
		while (!EmptyStack(&stch))
		{
			Pop(&ch, &stch);
			putchar(ch);
		}
		putchar('\n');
		printf("Enter next line (empty line to quit): ");
	}
	puts("Done!");

	system("pause");
	return 0;
}

//*******************************************************************************************

//list_b.c
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void InitializeStack(Stack * ps)
{
	ps->top = 0;
}

bool FullStack(const Stack * ps)
{
	return ps->top == MAXSTACK;
}

bool EmptyStack(const Stack *ps)
{
	return ps->top == 0;
}

bool Push(Item item, Stack * ps)
{
	if (ps->top == MAXSTACK)
		return false;
	else
	{
		ps->items[ps->top++] = item;
		return true;
	}
}

//*******************************************************************************************