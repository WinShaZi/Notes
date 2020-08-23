#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned int ul;
const char al[][7] = { "left", "center", "right" };
const char st[][4] = { "off", "on" };
ul id = 1;
ul size = 12;
ul align = 0;
ul B = 0;
ul I = 0;
ul U = 0;

void clean()
{
	while (getchar() != '\n')
		continue;
}

void _f()
{
	printf("Enter font id (0-255):");
	scanf("%u", &id);
	id &= 255;
}

void _s()
{
	printf("Enter font size (0-127):");
	scanf("%u", &size);
	size &= 127;
}

void _a()
{
	char ch;

	clean();
	printf("Select alignment:\nl)left    c)center    r)right\n");
	ch = tolower(getchar());
	if (ch == 'l')
		align = 0;
	if (ch == 'c')
		align = 1;
	if (ch == 'r')
		align = 2;
}

void _b()
{
	B ^= 1;
}

void _i()
{
	I ^= 1;
}

void _u()
{
	U ^= 1;
}

void show()
{
	puts("ID      SIZE    ALIGN    B       I       U");
	printf("%-8u%-8u%-8s%-8s%-8s%-8s\n\n", id, size, al[align], st[B], st[I], st[U]);
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