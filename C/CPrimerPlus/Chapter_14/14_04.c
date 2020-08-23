
// a
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define LEN 20

struct name
{
	char fname[LEN];
	char mname[LEN];
	char lname[LEN];
};

struct society
{
	int number[SIZE];
	struct name message[5];
};

show_a(struct society *pt, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (pt->message[i].mname[0] != ' ')
		{
			pt->message[i].mname[1] = '.';
			pt->message[i].mname[2] = '\0';
		}
		else
			pt->message[i].mname[2] = '\0';

		printf("%s, %s %s -- %d\n",
			pt->message[i].lname, pt->message[i].fname, pt->message[i].mname, pt->number[i]);
	}

}

int main()
{
	struct society money =
	{
		{11111,22222,33333,44444,55555},
		{
			{"AAA","BBB","CCC"},
			{"DDD","   ","FFF"},
			{"GGG","   ","III"},
			{"JJJ","   ","LLL"},
			{"MMM","NNN","OOO"}
		}
	};

	struct society *pt;
	pt = &money;
	show_a(pt, SIZE);


	system("pause");
	return 0;
}

//*******************************************************************************************

// b
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define LEN 20

struct name
{
	char fname[LEN];
	char mname[LEN];
	char lname[LEN];
};

struct society
{
	int number[SIZE];
	struct name message[5];
};

void show_b(struct society pt, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (pt.message[i].mname[0] != ' ')
		{
			pt.message[i].mname[1] = '.';
			pt.message[i].mname[2] = '\0';
		}
		else
			pt.message[i].mname[2] = '\0';

		printf("%s, %s %s -- %d\n",
			pt.message[i].lname, pt.message[i].fname, pt.message[i].mname, pt.number[i]);
	}

}

int main()
{
	struct society money =
	{
		{11111,22222,33333,44444,55555},
		{
			{"AAA","BBB","CCC"},
			{"DDD","   ","FFF"},
			{"GGG","   ","III"},
			{"JJJ","   ","LLL"},
			{"MMM","NNN","OOO"}
		}
	};

	show_b(money, SIZE);

	system("pause");
	return 0;
}

//*******************************************************************************************