#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
int compare(const T &t1, const T &t2)
{
	if (t1 < t2)
		return -1;
	if (t1 > t2)
		return 1;
	else 
		return 0;
}

int main()
{
	cout << compare<string>("A", "BBB") << endl;
    
	system("pause");
	return 0;
}