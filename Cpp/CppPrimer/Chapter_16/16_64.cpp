#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int count_element(const vector<const char *> vc, const char * c)
{
	int i = 0;
	vector<const char *> temp(vc);

	while (1)
	{
		auto iter = find(temp.begin(), temp.end(), c);
		if (iter == temp.end())
			break;
		temp.erase(iter);
		i++;
	}

	return i;
}

int main()
{
	vector<const char *> vs{ "A", "E", "E" ,"D", "E" };

	cout << count_element(vs, "E") << endl;

	system("pause");
	return 0;
}