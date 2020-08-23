#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	int num[] = { 1, 3, 5, 7, 9 ,7, 5, 3, 1 };
	vector<int> vi(begin(num), end(num));
	int n = 0 ;

	while (cin >> n)
		cout << count(vi.begin(), vi.end(), n) << endl;

	system("pause");
	return 0;
}