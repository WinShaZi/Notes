#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
void print(const T &t)
{
	for (size_t i = 0; i < t.size(); i++)
		cout << t[i] << endl;
}

int main()
{
	vector<int> vi{ 1, 2, 3, 4, 5 };
	print(vi);

	system("pause");
	return 0;
}