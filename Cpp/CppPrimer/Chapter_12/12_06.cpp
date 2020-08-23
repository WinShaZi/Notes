#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include <new>

using namespace std;

vector<int> * new_memory()
{
	return new vector<int>();
}

void print(const vector<int> &vi)
{
	for (auto n : vi)
		cout << n << ' ';
	cout << endl;
}

void read_cin(vector<int> *vi)
{
	int i;

	while (cin >> i)
		vi->push_back(i);
	print(*vi);
	delete vi;
}

int main()
{	
	auto p_vi = new_memory();

	read_cin(p_vi);
	delete p_vi;

	system("pause");
	return 0;
}