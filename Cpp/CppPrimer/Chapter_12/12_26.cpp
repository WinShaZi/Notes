#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <cstring>
#include <initializer_list>
#include <memory>

using namespace std;

int main()
{
	int n = 10;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	auto q = p;
	string s;

	while (cin >> s && q != p + n)
		alloc.construct(q++, s);
	cout << q - p << endl;

	alloc.destroy(p);
	
	system("pause");
	return 0;
}