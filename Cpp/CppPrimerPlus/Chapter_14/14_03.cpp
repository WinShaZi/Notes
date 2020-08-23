
//queuetp.h
//*******************************************************************************************

#ifndef QUEUETP_H_
#define QUEUETP_H_

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

class Worker
{
private:
	string fullname;
	long id;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Worker() :fullname("no one"), id(0l) {}
	Worker(const string& s, long n) :fullname(s), id(n) {}
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show()const = 0;
};
class Waiter :virtual public Worker
{
private:
	int panache;
protected:
	void Data()const;
	void Get();
public:
	Waiter() :Worker(), panache(0) {}
	Waiter(const string& s, long n, int p = 0) :Worker(s, n), panache(p) {}
	Waiter(const Worker& wk, int p = 0) :Worker(wk), panache(p) {}
	void Set();
	void Show()const;
};

class Singer :virtual public Worker
{
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	void Data()const;
	void Get();
private:
	static const char* pv[Vtypes];
	int voice;
public:
	Singer() :Worker(), voice(other) {}
	Singer(const string& s, long n, int v = other) :Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other) :Worker(wk), voice(v) {}
	void Set();
	void Show()const;
};
class SingerWaiter : public Singer, public Waiter
{
protected:
	void Data()const;
	void Get();
public:
	SingerWaiter() {}
	SingerWaiter(const string& s, long n, int p = 0, int v = other) :Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
	SingerWaiter(const Worker& wk, int p = 0, int v = other) :Worker(wk), Waiter(wk, p), Singer(wk, v) {}
	SingerWaiter(const Waiter& wt, int v = other) :Worker(wt), Waiter(wt), Singer(wt, v) {}
	SingerWaiter(const Singer& wt, int p = 0) :Worker(wt), Singer(wt), Waiter(wt, p) {}
	void Set();
	void Show()const;

};

template <class T>
class QueueTp
{
private:
	struct Node { T* item; struct Node* next; };
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qsize = 5;
public:
	QueueTp();
	~QueueTp();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool enqueue(T* item);
	bool dequeue(T* item);
};

template <class T>
QueueTp<T>::QueueTp()
{
	front = rear = NULL;
	items = 0;
}

template <class T>
QueueTp<T>::~QueueTp()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <class T>
bool QueueTp<T>::isempty()const
{
	return items == 0;
}

template <class T>
bool QueueTp<T>::isfull()const
{
	return items == qsize;
}

template <class T>
int QueueTp<T>::queuecount()const
{
	return items;
}

template <class T>
bool QueueTp<T>::enqueue(T* item)
{
	if (isfull())
		return false;
	QueueTp::Node* add = new QueueTp::Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;

	return true;
}

template <class T>
bool QueueTp<T>::dequeue(T* item)
{
	if (front == NULL)
		return false;
	item = front->item;
	items--;
	QueueTp::Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;

	return true;
}

#endif

//*******************************************************************************************

//queuetp.cpp
//*******************************************************************************************

#include "queuetp.h"

Worker::~Worker()
{

}

void Worker::Data()const
{
	cout << "Name : " << fullname << endl;
	cout << "Employee ID : " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID : ";
	while (!(cin >> id))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter worker's ID : ";
	}
	while (cin.get() != '\n');
}

void Waiter::Data()const
{
	cout << "Panache rating : " << panache << endl;
}

void Waiter::Get()
{
	cout << "Enter waiter's panache rating : ";
	while (!(cin >> panache))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter waiter's panache rating : ";
	}
	while (cin.get() != '\n');
}

void Waiter::Set()
{
	cout << "Enter waiter's name : ";
	Worker::Get();
	Get();
}

void Waiter::Show()const
{
	cout << "Category : waiter" << endl;
	Worker::Data();
	Data();
}

const char* Singer::pv[Singer::Vtypes] = { 
	"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

void Singer::Set()
{
	cout << "Enter singer's name : ";
	Worker::Get();
	Get();
}

void Singer::Show()const
{
	cout << "Category : singer" << endl;
	Worker::Data();
	Data();
}

void Singer::Data()const
{
	cout << "Vocal range : " << pv[voice] << endl;
}

void Singer::Get()
{
	int i;
	
	cout << "Enter number for singer's vocal range : " << endl;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << " : " << pv[i] << '\t';
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (!(cin >> voice))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Enter number for singer's vocal range : " << endl;
	}
	while (cin.get() != '\n');
}

void SingerWaiter::Set()
{
	cout << "Enter singing waiters name : ";
	Worker::Get();
	Get();
}
void SingerWaiter::Show()const
{
	cout << "Category : singing waiter" << endl;
	Worker::Data();
	Data();
}

void SingerWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();
}

void SingerWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include "queuetp.h"

const int SIZE = 5;

int main()
{
	QueueTp<Worker*> line;
	Worker* lolas[SIZE];

	int ct;

	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;

		cout << "Enter the employee category : " << endl
			<< "w : waiter\ts : singer\tt : singerWaiter\tq : quit" << endl;
		cin >> choice;
		while (strchr("wstq", choice = tolower(choice)) == NULL)
		{
			cout << "Please enter a w,s,t or q : ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':lolas[ct] = new Waiter; break;
		case 's':lolas[ct] = new Singer; break;
		case 't':lolas[ct] = new SingerWaiter; break;
		default:lolas[ct] = nullptr; break;
		}
		while (cin.get() != '\n');
		lolas[ct]->Set();
		line.enqueue(&lolas[ct]);
	}
	if (ct != 0)
	{
		cout << "Here is your staff : " << endl;
		for (int i = 0; i < ct; i++)
		{
			lolas[i]->Show();
			cout << endl;
		}
		for (int i = 0; i < ct; i++)
			delete lolas[i];
	}
	cout << "Bye" << endl;

	system("pause");
	return 0;
};

//*******************************************************************************************