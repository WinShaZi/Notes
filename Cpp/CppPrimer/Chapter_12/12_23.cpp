#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <new>
#include <cstring>

using namespace std;

int main()
{
	string s1("A");
	string s2("B");

	auto pc = new char[s1.size() + s2.size() + 1]();

	strcat(pc, s1.c_str());
	strcat(pc, s2.c_str());

	cout << pc << endl;

	delete[] pc;

	system("pause");
	return 0;
}