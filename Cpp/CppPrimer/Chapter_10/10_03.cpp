#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	vector<int> vi(10, 10);

	cout << accumulate(vi.cbegin(), vi.cend(), 0) << endl;
	
	system("pause");
	return 0;
}