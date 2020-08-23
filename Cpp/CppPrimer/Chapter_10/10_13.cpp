#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <numeric>

using namespace std;

bool isShorter(const string &st)
{
	return st.size() > 5;
}

vector<string>::iterator elimDups(vector<string> &vs)
{
	sort(vs.begin(), vs.end());
	auto end = unique(vs.begin(), vs.end());
	vs.erase(end, vs.end());

	return partition(vs.begin(), vs.end(), isShorter);
}

int main()
{
	vector<string> vs{ "vector", "deque", "list", "forward_list", "array", "string" };

	for (auto n : vs)
		cout << n << ' ';
	cout << endl;


	auto pd = elimDups(vs);
	
	for (auto n : vs)
	{
		if (n == *pd)
			break;
		cout << n << ' ';
	}
	cout << endl;
	
	system("pause");
	return 0;
} 