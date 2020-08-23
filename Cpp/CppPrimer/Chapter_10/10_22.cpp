#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

using namespace std::placeholders;

bool check_size(const string &st, const size_t &sz)
{
	return st.size() <= sz;
}

size_t elimDups(vector<string> &vs, const size_t &sz)
{
	sort(vs.begin(), vs.end());
	auto end = unique(vs.begin(), vs.end());
	vs.erase(end, vs.end());

	return count_if(vs.begin(), vs.end(), bind(check_size, _1, _2));
}

int main()
{
	vector<string> vs{ "vector", "deque", "list", "forward_list", "array", "string" };

	for (auto n : vs)
		cout << n << ' ';
	cout << endl;


	cout << elimDups(vs, 6) << endl;

	system("pause");
	return 0;
}