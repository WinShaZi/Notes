
//stack.h
//*******************************************************************************************

#ifndef STACK_H_
#define STACK_H_

struct customer 
{
	char fullname[35];
	double payment;
};

typedef customer Item;

class Stack
{
private:
	enum { MAX = 10 };
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
};

#endif

//*******************************************************************************************

//stack.cpp
//*******************************************************************************************

#include "stack.h"

Stack::Stack()
{
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const Item& item)
{
	if (top < MAX)
	{
		items[top++] = item;

		return true;
	}
	else
		return false;
}

bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
	using namespace std;

	Stack st;
	char ch;
	customer temp = {
		"",
		0.0
	};
	double totalpayment = 0.0;

	cout << "Please enter A to add customer's information" << endl;
	cout << "D to delete customer's information, and Q to quit" << endl;
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << "\a";
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter the name : ";
			cin.getline(temp.fullname, 35);
			cout << "Enter the payment : ";
			cin >> temp.payment;
			if (st.isfull())
				cout << "stack already full." << endl;
			else
			{
				st.push(temp);
				totalpayment += temp.payment;
			}
			break;
		case 'D':
		case 'd':
			if (st.isempty())
				cout << "stack already empty." << endl;
			else
			{
				totalpayment -= temp.payment;
				st.pop(temp);
				cout << "The information of " << temp.fullname << " has been deleted." << endl;
			}
			break;
		}
		cout << "Please enter A to add customer's information" << endl;
		cout << " D to delete customer's information, and Q to quit" << endl;
	}
	cout << "Service end.\nThe total payment is " << totalpayment << endl;
	cout << "Bye!" << endl;

	system("pause");
	return 0;
}

//*******************************************************************************************