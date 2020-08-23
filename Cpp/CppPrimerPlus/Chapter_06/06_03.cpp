#include <iostream>

using namespace std;

void mean();

int main()
{
	char ch;

	mean();
	while (cin >> ch && ch != EOF)
	{
		while (cin.get() != '\n');
		switch (ch)
		{
		case 'c': cout << "A tiger is a carnivore" << endl;
			break;
		case 'p': cout << "Mozart is a pianist" << endl;
			break;
		case 't': cout << "A maple is a tree" << endl;
			break;
		case 'g': cout << "COD is a game" << endl;
			break;
		default: cout << "Please enter a c, p, t, or g : ";
		}
	}

	system("pause");
	return 0;
}

void mean()
{
	cout << "Please enter one of the following choices : " << endl;
	cout << "c) carnivore           p)pianist            " << endl;
	cout << "t) tree                g)game               " << endl;
}