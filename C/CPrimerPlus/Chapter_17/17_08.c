
//tree.h
//*******************************************************************************************

#ifndef _TREE_H
#define _TREE_H

#include <stdbool.h>

#define TREEMAX 20

typedef struct item
{
	char petname[20];
	char petkind[20];
}Item;

typedef struct node_list
{
	Item item;
	struct node_list * next;
}List;

typedef struct node_tree
{
	List * list;
	int list_size;
	struct node_tree * left;
	struct node_tree * right;
}Node;

typedef struct tree
{
	Node * root;
	int size;
}Tree;


void InitTree(Tree * ptree);
bool TreeIsEmpty(const Tree * ptree);
bool TreeIsFull(const Tree * ptree);
int TreeItemCount(const Tree * ptree);
bool InTree(const Item * pi, const Tree * ptree);
bool AddTreeItem(const Item * pi, Tree * ptree);
bool DeleteItem(const Item * pi, Tree * ptree);
void Traverse(const Tree * ptree, void(*pfun)(List * list));
void DeleteAll(Tree * ptree);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair
{
	Node * parent;
	Node * child;
}Pair;

static bool AddListItem(const Item * pi, Node * root);
static List * MakeListNode(const Item * pi);
static Node * MakeTreeNode(const Item * pi);
static AddTreeNode(Node * new_node, Node * root);
static Pair SeekItem(const Item * pi, const Tree * ptree);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static bool SeekListItem(const Item * pi, List * pl);
static DeNode(const Item * pi, Node ** ptr);
static List * DeListNode(const Item * pi, List * pl);
static InOrder(const Node * root, void(*pfun)(List * list));
static DeleteAllNodes(Node * root);
static DeList(List * list);
static DeleteAllList(Node * root);

static bool AddListItem(const Item * pi, Node * root)
{
	List * new_listnode, *temp = root->list;
	new_listnode = MakeListNode(pi);
	if (new_listnode == NULL)
	{
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	while (NULL != temp->next)
		temp = temp->next;
	temp->next = new_listnode;
	root->list_size++;
	return true;
}

static List * MakeListNode(const Item* pi)
{
	List * new_list;
	new_list = (List *)malloc(sizeof(List));
	if (new_list != NULL)
	{
		new_list->item = *pi;
		new_list->next = NULL;
	}

	return new_list;
}

static Node * MakeTreeNode(const Item * pi)
{
	Node * new_node;
	List * new_list_node;

	new_list_node = MakeListNode(pi);
	if (new_list_node == NULL)
		return NULL;
	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->list = new_list_node;
		new_node->list_size = 1;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static AddTreeNode(Node * new_node, Node * root)
{
	if (ToLeft(&new_node->list->item, &root->list->item))
	{
		if (NULL == root->left)
			root->left = new_node;
	}
	else if (ToRight(&new_node->list->item, &root->list->item))
	{
		if (NULL == root->right)
			root->right = new_node;
	}

}

static bool ToLeft(const Item * i1, const Item * i2)
{
	if (strcmp(i1->petname, i2->petname) < 0)
		return true;
	return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
	if (strcmp(i1->petname, i2->petname) > 0)
		return true;
	return false;
}

static bool SeekListItem(const Item * pi, List * pl)
{
	List * temp = pl;
	while (NULL != temp)
	{
		if (strcmp(pi->petkind, temp->item.petkind) == 0)
			return true;
		temp = temp->next;
	}

	return false;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (NULL == look.child)
		return look;
	while (NULL != look.child)
	{
		if (ToLeft(pi, &look.child->list->item))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &look.child->list->item))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
		{
			break;
		}

	}

	return look;
}

static DeNode(const Item * pi, Node ** ptr)
{
	Node * temp;
	if (1 == (*ptr)->list_size)
	{
		if (NULL == (*ptr)->left)
		{
			temp = *ptr;
			*ptr = (*ptr)->right;
			free(temp);
		}
		else if (NULL == (*ptr)->right)
		{
			temp = *ptr;
			*ptr = (*ptr)->left;
			free(temp);
		}
		else
		{
			temp = (*ptr)->left;
			while (NULL != temp->right)
				temp = temp->right;
			temp->right = (*ptr)->right;
			temp = *ptr;
			*ptr = (*ptr)->left;
			free(temp);
		}
	}
	else if ((*ptr)->list_size > 1)
	{
		(*ptr)->list = DeListNode(pi, (*ptr)->list);
		(*ptr)->list_size--;
	}
}

static List * DeListNode(const Item * pi, List * pl)
{
	List * phead = pl;
	List * temp;
	if (strcmp(pi->petkind, phead->item.petkind) == 0)
	{
		phead = pl->next;
		free(pl);
	}
	else
	{
		do
		{
			temp = pl;
			pl = pl->next;
		} while (strcmp(pi->petkind, pl->item.petkind) != 0);

		temp->next = pl->next;
		free(pl);
	}
	return phead;
}

static InOrder(const Node * root, void(*pfun)(List * list))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->list);
		InOrder(root->right, pfun);
	}
}

static DeleteAllNodes(Node * root)
{
	Node * temp = root;

	if (root != NULL)
	{
		temp = root->right;
		DeleteAllNodes(root->left);
		DeList(root->list);
		free(root);
		DeleteAllNodes(temp);
	}
}

static DeList(List * list)
{
	List * temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}

}

void InitTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	return ptree->root == NULL;
}

bool TreeIsFull(const Tree * ptree)
{
	return ptree->size >= TREEMAX;
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool InTree(const Item * pi, const Tree * ptree)
{
	Pair look = SeekItem(pi, ptree);
	return look.child != NULL && SeekListItem(pi, look.child->list);
}

bool AddTreeItem(const Item * pi, Tree * ptree)
{
	Node * new_node;
	Pair seek;

	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is ull\n");
		return false;
	}
	seek = SeekItem(pi, ptree);
	if (seek.child != NULL)
	{
		if (AddListItem(pi, seek.child));
		return true;
		return false;
	}
	new_node = MakeTreeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddTreeNode(new_node, ptree->root);
	ptree->size++;

	return true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	int i = TreeItemCount(ptree);
	if (NULL == look.child)
		return false;
	if (!SeekListItem(pi, look.child->list))
		return false;
	DeNode(pi, &look.child);
	int j = TreeItemCount(ptree);
	if (i == j)
		ptree->size--;
	if (ptree->size == 0)
		ptree->root = NULL;

	return true;
}

void Traverse(const Tree * ptree, void(*pfun)(List * list))
{
	if (ptree->root != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
	if (ptree->root != NULL)
		DeleteAllNodes(ptree->root);
	ptree->size = 0;
}

//*******************************************************************************************

//tree.c
//*******************************************************************************************

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#define SIZE 20

char menu();
addpet(Tree * pt);
void droppet(Tree * pt);
showpets(const Tree * pt);
void findpet(const Tree * pt);
printitem(List * list);
uppercase(char * str);
int ListItemCount(Node * root);

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

	return 0;
}

int main()
{
	Tree pets;
	char choice = 0;
	int conut = 0, temp = 0;

	InitTree(&pets);
	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
		case 'a': addpet(&pets);
			break;
		case 'l': showpets(&pets);
			break;
		case 'f': findpet(&pets);
			break;
		case 'n':
			conut = ListItemCount(pets.root);
			conut -= temp;
			temp += conut;
			printf("%d pets in club\n", conut);
			break;
		case 'd': droppet(&pets);
			break;
		default: puts("Switching error");
		}
	}
	DeleteAll(&pets);
	puts("Bye.");

	system("pause");
	return 0;
}

char menu()
{
	int ch = '\0';

	puts("Nerfville pet Club Membership Program");
	puts("Enter the letter corresponding to your choice : ");
	puts("a)add a per		l)show list of pets");
	puts("n)number of pets	f)find pets");
	puts("d)delete apet		q)quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		if (strchr("alrfndq", ch) == NULL)
			puts("Please enter an a, l, f, n, d, or q : ");
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';

	return ch;
}

addpet(Tree * pt)
{
	Item temp;

	if (TreeIsFull(pt))
		puts("No room in the club!");
	else
	{
		puts("Please enter name of pet : ");
		s_gets(temp.petname, SIZE);
		puts("Please enter pet kind : ");
		s_gets(temp.petkind, SIZE);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddTreeItem(&temp, pt);
	}
}

showpets(const Tree * pt)
{
	if (TreeIsEmpty(pt))
		puts("No enteries!");
	else
		Traverse(pt, printitem);
}

printitem(List * list)
{
	while (list != NULL)
	{
		printf("pet : %-19s kind : %-19s\n", list->item.petname,
			list->item.petkind);
		list = list->next;
	}
}

void findpet(const Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet you wish to find : ");
	s_gets(temp.petname, SIZE);
	puts("Please enter pet kind : ");
	s_gets(temp.petkind, SIZE);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ", temp.petkind, temp.petname);
	if (InTree(&temp, pt))
		printf("is a member.\n");
	else
		printf("is not a member .\n");
}

void droppet(Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}
	puts("Please enter name of pet you wish to delete : ");
	s_gets(temp.petname, SIZE);
	puts("Please enter pet dind : ");
	s_gets(temp.petkind, SIZE);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ", temp.petname, temp.petkind);

	if (DeleteItem(&temp, pt))
		printf("is dropped from the club.\n");
	else
		printf("is not a member.\n");
}

uppercase(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

int ListItemCount(Node * root)
{
	static int conut = 0;

	if (root != NULL)
	{
		ListItemCount(root->left);
		conut += root->list_size;
		ListItemCount(root->right);
	}

	return conut;
}

//*******************************************************************************************