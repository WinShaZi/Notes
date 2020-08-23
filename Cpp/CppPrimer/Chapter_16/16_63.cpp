#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

template <typename T, typename N>
int count_element(const T& t, const N& n)
{
	int i = 0;
	T temp(t);

	while (1)
	{
		auto iter = find(temp.begin(), temp.end(), n);
		if (iter == temp.end())
			break;
		temp.erase(iter);
		i++;
	}

	return i;
}

int main()
{
	vector<int> vi{ 1, 3, 5, 7, 5, 9 };
	vector<double> vb{ 1.1, 2.2, 2.2, 4.4, 5.5 };
	vector<string> vs{ "A", "E", "E" ,"D", "E" };

	cout << count_element(vi, 5) << endl;
	cout << count_element(vb, 2.2) << endl;
	cout << count_element(vs, "E") << endl;

	system("pause");
	return 0;
}