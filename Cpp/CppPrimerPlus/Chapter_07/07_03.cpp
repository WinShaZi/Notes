#include <iostream>

using namespace std;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_a(box str);
void show_b(box* ps);

int main()
{
	box* ps = new box;
	box str = {
		"China",
		10.0,
		20.0,
		30.0,
		6000.0
	};

	*ps = str;

	show_a(str);
	show_b(ps);

    delete ps;

	system("pause");
	return 0;
}

void show_a(box str)
{
	cout << "a : " << endl;
	cout << str.maker << endl;
	cout << str.height << endl;
	cout << str.width << endl;
	cout << str.length << endl;
	cout << str.volume << endl;
}

void show_b(box* ps)
{
	ps->volume = ps->height * ps->width * ps->length;
	cout << "b : " << endl;
	cout << ps->maker << endl;
	cout << ps->height << endl;
	cout << ps->width << endl;
	cout << ps->length << endl;
	cout << ps->volume << endl;
}