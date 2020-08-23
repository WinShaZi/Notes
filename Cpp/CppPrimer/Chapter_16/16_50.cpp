#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

template <typename T> 
void f(T)
{
	cout << "void f(T)" << endl;
}

template <typename T> 
void f(const T *)
{
	cout << "void f(const T *)" << endl;
}

template <typename T> 
void g(T)
{
	cout << "void g(T)" << endl;
}

template <typename T> 
void g(T *)
{
	cout << "void g(T *)" << endl;
}

int main()
{
    int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;

	g(42);
	f(42);
	g(p);
	f(p);
	g(ci);
	f(ci);
	g(p2);
	f(p2);

	system("pause");
    return 0;
}