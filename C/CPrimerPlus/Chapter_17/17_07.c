//list.h
//*******************************************************************************************

#ifndef _TREE_H_
#define _TREE_H_

#include <stdbool.h>

#define SLEN 81
#define MAXITEMS 100

typedef struct item
{
	char wrd[SLEN];
	int count;
} Item;

typedef struct node
{
	Item item;
	struct node * left;
	struct node * right;
} Node;

typedef struct tree
{
	Node * root;
	int size;
} Tree;

InitializeTree(Tree * ptree);
bool TreeIsEmpty(const Tree * ptree);
bool TreeIsFull(const Tree * ptree);
int TreeItemCount(const Tree * ptree);
bool AddItem(const Item * pi, Tree * ptree);
bool InTree(const Item * pi, const Tree * ptree);
bool DeleteItem(const Item * pi, Tree * ptree);
Traverse(const Tree * ptree, void(*pfun)(Item item));
DeleteAll(Tree * ptree);
const Item * WhereInTree(const Item * pi, const Tree * ptree);
#endif

//*******************************************************************************************

//list_a.c
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

#define SLEN 81

printitem(Item item)
{
	printf("%3d: %s\n", item.count, item.wrd);
}

char menu()
{
	int ch = '\0';

	puts("Word counting program");
	puts("Enter the letter corresponding to your choice : ");
	puts("s) show word list f) find a word");
	puts("q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		if (strchr("sfq", ch) == NULL)
			puts("Please enter an s, f, or q : ");
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';
	return ch;
}

void showwords(const Tree * pt)
{
	if (TreeIsEmpty(pt))
		puts("No entries!");
	else
		Traverse(pt, printitem);
}

void findword(const Tree * pt)
{
	char word[SLEN] = "\0";
	Item entry;
	const Item * pi = NULL;

	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}
	printf("Enter the word to find : ");
	scanf("%s", word, SLEN);
	while (getchar() != '\n')
		continue;
	strcpy_s(entry.wrd, SLEN, word);
	pi = WhereInTree(&entry, pt);
	if (pi == NULL)
		printf("%s is not in the list.\n", word);
	else
		printf("%s appears %d times.\n", word, pi->count);
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
	Tree wordcount;
	FILE * fp = NULL;
	char filename[SLEN] = "\0";
	char word[SLEN] = "\0";
	Item entry;
	char choice = '\0';
	printf("Enter name of file to be processed : \n");
	s_gets(filename, SLEN);
	fopen_s(&fp, filename, "r");
	if (fp == 0)
	{
		printf("Can't open file %s. Bye.\n", filename);
		exit(EXIT_FAILURE);
	}
	InitializeTree(&wordcount);
	while (fscanf_s(fp, "%s", word, SLEN) == 1 && !TreeIsFull(&wordcount))
	{
		strcpy_s(entry.wrd, SLEN, word);
		AddItem(&entry, &wordcount);
	}
	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
		case 's': showwords(&wordcount);
			break;
		case 'f': findword(&wordcount);
			break;
		default: puts("Switching error");
		}
	}
	fclose(fp);
	puts("Done");

	system("pause");
	return 0;
}

//*******************************************************************************************

//list_b.c
//*******************************************************************************************

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct pair
{
	Node * parent;
	Node * child;
} Pair;

static Node * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static AddNode(Node * new_node, Node * root);
static InOrder(const Node * root, void(*pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static DeleteNode(Node **ptr);
static DeleteAllNodes(Node * ptr);

InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree * ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
	Node * new;
	Pair seek;
	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	if ((seek = SeekItem(pi, ptree)).child != NULL)
	{
		seek.child->item.count++;
		return true;
	}
	new = MakeNode(pi);
	if (new == NULL)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = new;
	else
		AddNode(new, ptree->root);

	return true;
}

bool InTree(const Item * pi, const Tree * ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

const Item * WhereInTree(const Item * pi, const Tree * ptree)
{
	Node * pn;
	pn = SeekItem(pi, ptree).child;
	if (pn != NULL)
		return &(pn->item);
	else
		return NULL;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;
	if (look.child->item.count > 0)
		look.child->item.count--;
	else
	{
		if (look.parent == NULL)
			DeleteNode(&ptree->root);
		else if (look.parent->left == look.child)
			DeleteNode(&look.parent->left);
		else
			DeleteNode(&look.parent->right);
		ptree->size--;
	}

	return true;
}

Traverse(const Tree * ptree, void(*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

DeleteAll(Tree * ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static InOrder(const Node * root, void(*pfun)(Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static DeleteAllNodes(Node * root)
{
	Node * pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

static AddNode(Node * new_node, Node * root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else
	{
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item * i1, const Item * i2)
{
	if (strcmp(i1->wrd, i2->wrd) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
	if (strcmp(i1->wrd, i2->wrd) > 0)
		return true;
	else
		return false;
}

static Node * MakeNode(const Item * pi)
{
	Node * new_node;
	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->item.count = 1;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}

static DeleteNode(Node **ptr)
{
	Node * temp;
	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else
	{
		for (temp = (*ptr)->left; temp->right != NULL;
			temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

//*******************************************************************************************