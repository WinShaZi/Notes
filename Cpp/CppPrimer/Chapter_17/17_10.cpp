#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <bitset>
#include <numeric>

using namespace std;


int main()
{
	vector<int> vi{ 1, 2, 3, 5, 8, 13, 21 };

	for (int i = 0; i < vi.size(); i++)
	{
		bitset<8> bv(vi[i]);
		cout << bv << endl;
	}
	

	system("pause");
	return 0;
}