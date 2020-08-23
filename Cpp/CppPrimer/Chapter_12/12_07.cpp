#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include <new>

using namespace std;

shared_ptr<vector<int>> new_memory()
{
	return make_shared<vector<int>>();
}

void print(shared_ptr<vector<int>> vi)
{
	for (auto n : *vi)
		cout << n << ' ';
	cout << endl;
}

void read_cin(shared_ptr<vector<int>> vi)
{
	int i;

	while (cin >> i)
		vi->push_back(i);
	print(vi);
}

int main()
{	
	auto p_vi = new_memory();

	read_cin(p_vi);

	system("pause");
	return 0;
}