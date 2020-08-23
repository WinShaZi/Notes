
//list.h
//*******************************************************************************************

#ifndef LIST_H_
#define LIST_H_

typedef long long Item;

class List
{
private:
	enum { MAX = 10 };
	Item items[MAX];
	int top = 0;
public:
	List();
	bool isempty() const;
	bool isfull() const;
	bool add(const Item& item);
	void visit(void (*pf)(Item& item));
	void showitem() const;
};

void square(Item& item);

#endif

//*******************************************************************************************

//list.cpp
//*******************************************************************************************

#include <iostream>
#include "list.h"

List::List()
{
	top = 0;
}

bool List::isempty() const
{
	return top == 0;
}

bool List::isfull() const
{
	return top == MAX;
}

bool List::add(const Item& item)
{
	if (top < MAX)
	{
		items[top++] = item;

		return true;
	}
	else
		return false;
}

void List::visit(void(*pf)(Item& item))
{
	for (int i = 0; i < top; i++)
	{
		pf(items[i]);
	}
}

void List::showitem() const
{
	for (int i = 0; i < top; i++)
	{
		std::cout << "#" << i + 1 << ": " << items[i] << std::endl;
	}
}

void square(Item& item)
{
	item *= item;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "list.h"
#include <cctype>

using namespace std;

int main()
{
	char ch;
	List li;
	long long data;

	cout << "Please enter C to create your list" << endl;
	cout << " P to process the list, S to show the items, Q to quit : " << endl;
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n');
		if (!isalpha(ch))
		{
			cout << "\a";
			continue;
		}
		switch (ch)
		{
		case 'C':
		case 'c':
			if (li.isfull())
				cout << "The list already full" << endl;
			else
			{
				cout << "Enter the data : ";
				cin >> data;
				li.add(data);
			}
			break;
		case 'P':
		case 'p':
			if (li.isempty())
				cout << "The list already empty" << endl;
			else
			{
				li.visit(square);
				cout << "Every data square" << endl;
			}
			break;
		case 'S':
		case 's':
			li.showitem();
			break;
		}
		cout << "Please enter C to create your list" << endl;
		cout << " P to process the list, S to show the items, Q to quit : " << endl;
	}
	li.showitem();
	cout << "Bye!" << endl;

	system("pause");
	return 0;
}

//*******************************************************************************************