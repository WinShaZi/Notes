#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vi(10, 100);

	fill_n(vi.begin(), vi.size(), 0);

	for (auto n : vi)
		cout << n << endl;
	
	system("pause");
	return 0;
} 