#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
auto sum(const T &t1, const T &t2) -> decltype(t1 + t2)
{
	return t1 + t2;
}

int main()
{
	unsigned int i = 100000000;
	unsigned long long j = 1000 * i;

	cout << sum<decltype(i + j)>(i, j) << endl;
    
	system("pause");
	return 0;
}