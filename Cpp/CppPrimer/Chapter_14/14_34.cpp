#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

struct Print
{
	template<class T>
	T & operator()(bool b, T t1, T t2)
	{
		return (b ? t1 : t2);
	}
};

int main()
{
	Print p;

	cout << p(1 == 1, 1, 0) << endl;

	system("pause");
	return 0;
}