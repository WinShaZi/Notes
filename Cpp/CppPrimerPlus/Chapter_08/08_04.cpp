#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
	char* str;
	int ct;
};

void set(stringy& bean, char test[]);
void show(const stringy& bean, int n = 1);
void show(const char test[], int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn,t what is used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");

	system("pause");
	return 0;
}

void set(stringy& bean, char test[])
{
	bean.ct = strlen(test) + 1;
	bean.str = new char[bean.ct];
	strcpy(bean.str, test);
}

void show(const stringy& bean, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << bean.str << endl;
		cout << bean.ct << endl;
	}
	cout << endl;
}

void show(const char test[], int n)
{
	for (int i = 0; i < n; i++)
		cout << test << endl;
	cout << endl;
}