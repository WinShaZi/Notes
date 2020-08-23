#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <numeric>
#include <functional>

using namespace std;

using namespace std::placeholders;

bool check_size(const string & st, const size_t &sz)
{
	return st.size() > sz;
}

vector<string>::iterator elimDups(vector<string> &vs, string::size_type sz)
{
	sort(vs.begin(), vs.end());
	auto end = unique(vs.begin(), vs.end());
	vs.erase(end, vs.end());

	return partition(vs.begin(), vs.end(), bind(check_size, _1, sz));
}

int main()
{
	vector<string> vs{ "vector", "deque", "list", "forward_list", "array", "string" };

	for (auto n : vs)
		cout << n << ' ';
	cout << endl;


	auto pd = elimDups(vs, 5);

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