#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct X
{
	X() { cout << "X()" << endl; }
	X(const X &) { cout << "X(const X&)" << endl;}
	~X() { cout << "~X()" << endl; }
	X & operator=(const X &) { cout << "X & operator=(const X &)" << endl; return *this; }
};

void input(X &x1, X *x2)
{
	vector<X> vx;
	
	vx.push_back(x1);
	cout << endl;

	vx.push_back(*x2);
	cout << endl;
}

int main()
{
	

	X x1;
	cout << endl;

	X *x2 = new X(x1);
	cout << endl;

	input(x1, x2);

	delete x2;

	system("pause");
	return 0;
}