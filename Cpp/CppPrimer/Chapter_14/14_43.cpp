#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main()
{
	vector<int> vi{ 2, 4, 6, 8, 10 };

	cout << (find_if(vi.begin(), vi.end(), bind(modulus<int>(), _1, 2)) == vi.end() ? "true" : "false") << endl;

	system("pause");
	return 0;
}