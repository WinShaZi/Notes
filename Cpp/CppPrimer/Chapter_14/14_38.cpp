#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <iomanip>

using namespace std;

class Count
{
private:
	size_t size;
public:
	Count(size_t si) : size(si) { }
	bool operator()(const size_t &st_size) const { return size < st_size; }
};

int main()
{
	ifstream fin("data");
	string st;
	vector<size_t> vt;

	while (fin >> st)
	{
		Count co(vt.size());
		if (co(st.size()))
			vt.resize(st.size());
		vt[st.size() - 1]++;
	}

	cout.flags(ios::right);
	for (size_t i = 0; i < vt.size(); i++)
		cout << setw(2) << i + 1 << ' ' << setw(5) << vt[i] << endl;

	fin.close();

	system("pause");
	return 0;
}