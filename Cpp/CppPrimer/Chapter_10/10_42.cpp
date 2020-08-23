#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	list<string> ls{ "you", "can", "you", "up", "no", "can", "no", "bb" };

	ls.sort();
	ls.unique();

	for (auto n : ls)
		cout << n << ' ';
	cout << endl;
	
	system("pause");
	return 0;
} 