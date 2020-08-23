#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned int ui;

struct bit
{
	ui id : 8;
	ui size : 7;
	ui : 1;
		 ui align : 2;
		 ui B : 1;
		 ui I : 1;
		 ui U : 1;
}change = { 1, 12, 0, 0, 0, 0 };

const char al[][7] = { "left", "center", "right" };
const char st[][4] = { "off", "on" };

void clean()
{
	while (getchar() != '\n')
		continue;
}

void _f()
{
	ui n = 0;

	printf("Enter font id (0-255):");
	if (scanf("%u", &n))
		change.id = (n & 255);
}

void _s()
{
	ui n;

	printf("Enter font size (0-127):");
	if (scanf("%u", &n))
		change.size = (n & 127);
}

void _a()
{
	char ch = '\0';

	clean();
	printf("Select alignment:\nl)left    c)center    r)right\n");
	ch = tolower(getchar());
	if (ch == 'l')
		change.align = 0;
	if (ch == 'c')
		change.align = 1;
	if (ch == 'r')
		change.align = 2;
}

void _b()
{
	change.B ^= 1;
}

void _i()
{
	change.I ^= 1;
}

void _u()
{
	change.U ^= 1;
}

void show()
{
	puts("ID      SIZE    ALIGN   B       I       U");
	printf("%-8u%-8u%-8s%-8s%-8s%-8s\n\n",
		change.id, change.size, al[change.align], st[change.B], st[change.I], st[change.U]);
}

void menu()
{
	puts("f)change font    s)change size    a)change alignment");
	puts("b)toggle bold    i)toggle italic  u)toggle underline");
	puts("q)quit");
}

int main()
{
	char ch = '\0';

	show();
	menu();

	while (ch = tolower(getchar()))
	{
		if (ch == 'q')
			break;
		switch (ch)
		{
		case 'f':
			_f();
			break;
		case 's':
			_s();
			break;
		case 'a':
			_a();
			break;
		case 'b':
			_b();
			break;
		case 'i':
			_i();
			break;
		case 'u':
			_u();
			break;
		default:
			break;
		}
		system("CLS");
		show();
		menu();
		clean();
	}
	puts("Bye");

	system("pause");
	return 0;
}