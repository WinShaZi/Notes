#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<int> &vi)
{
	sort(vi.begin(), vi.end());
	auto end = unique(vi.begin(), vi.end());
	vi.erase(end, vi.end());
}

int main()
{
	vector<int> vi{ 1, 2, 3, 4, 5, 5, 6, 6, 6, 7, 8, 9, 9 };

	for (auto n : vi)
		cout << n << ' ';
	cout << endl;

	elimDups(vi);
	
	for (auto n : vi)
		cout << n << ' ';
	cout << endl;
	
	system("pause");
	return 0;
} 