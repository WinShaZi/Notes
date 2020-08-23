#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

void f(int v1, int& v2)
{
	cout << v1 << " " << ++v2 << endl;
}

void g(int&& i, int& j)
{
	cout << i << " " << ++j << endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	f(forward<T2>(t2), forward<T1>(t1));
}

int main()
{
	int i = 0;

	flip(f, i, 42);
	flip(g, i, 42);
    
	system("pause");
	return 0;
}