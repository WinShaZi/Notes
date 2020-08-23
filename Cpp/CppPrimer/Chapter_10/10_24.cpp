#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <cstdlib>
#include <ctime>

using namespace std;

using namespace std::placeholders;

bool check_size(const int sz, const string &st)
{
	return sz > st.size();
}

int find_size(const vector<int> &vi, const string &st)
{
	auto pd = find_if(vi.begin(), vi.end(), bind(check_size, _1, st));

	return *pd;
}

int main()
{
	srand(unsigned(time(0)));
	string st = "C++ primer";
	vector<int> vi;

	for (int i = 0; i < 10; i++)
	{
		vi.push_back(rand() % 20 + 1);
		cout << vi[i] << ' ';
	}
	cout << endl;

	cout << "Size : " << st.size() << " " << find_size(vi, st) << endl;

	system("pause");
	return 0;
}