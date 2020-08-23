
//stock.h
//*******************************************************************************************

#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum { MAX = 10 };
	Item* pitems;
	int size;
	int top;
public:
	Stack(int n = MAX);
	Stack(const Stack& st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack& operator=(const Stack& st);
	void show()const;
};

#endif

//*******************************************************************************************

//stock.cpp
//*******************************************************************************************

#include <iostream>
#include "stack.h"

Stack::Stack(int n)
{
	size = n;
	pitems = new Item[n];
	top = 0;
}

Stack::Stack(const Stack& st)
{
	size = st.size;
	pitems = new Item[size]{ 0 };
	for (top = 0; top < size; ++top)
		pitems[top] = st.pitems[top];
}

Stack::~Stack()
{
	delete[] pitems;
	pitems = 0;
	size = top = 0;
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
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		pitems[top] = 0;
		item = pitems[--top];
		return true;
	}
	else
		return false;
}

Stack& Stack::operator=(const Stack& st)
{
	if (this == &st)
		return *this;

	delete[] pitems;
	size = st.size;
	top = st.top;
	pitems = new Item[size + 1];
	for (int i = 0; i < top; i++)
		pitems[i] = st.pitems[i];

	return *this;
}

void Stack::show()const
{
	for (int i = 0; i < top; i++)
		std::cout << pitems[i] << ' ';
	std::cout << std::endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include <cctype>
#include "stack.h"

using namespace std;

int main()
{
	Stack st, ss;
	char ch;
	unsigned long po;

	cout << "Input A add a number, input R remove a number," << endl;
	cout << "input Q to quit" << endl;
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n');
		switch (ch)
		{
		case 'A':
		case 'a':
			if (st.isfull())
				cout << "Is full" << endl;
			else
			{
				cout << "Input a number : ";
				cin >> po;
				st.push(po);
			}
			break;
		case 'R':
		case 'r':
			if (st.isempty())
				cout << "Is empty" << endl;
			else
			{
				st.pop(po);
				cout << "PO #" << po << " popped" << endl;
			}
			break;
		}
		cout << "Input A add a number, input R remove a number," << endl;
		cout << "input Q to quit" << endl;
	}
	ss = st;
	ss.show();
	cout << "Bye" << endl;

	sysetm("pause");
	return 0;
}

//*******************************************************************************************