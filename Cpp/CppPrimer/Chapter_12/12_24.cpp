#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <new>
#include <cstring>

using namespace std;

int main()
{
	string st;

	cin >> st;

	auto pc = new char[st.size() + 1]();

	strcpy(pc, st.c_str());
	cout << pc << endl;

	delete[] pc;

	system("pause");
	return 0;
}