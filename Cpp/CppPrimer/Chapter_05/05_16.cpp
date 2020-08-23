#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vi(10, 100);
	auto pd = vi.begin();

	for (auto n : vi)
		cout << n << ' ';
	
	while (pd != vi.end())
		cout << *pd++ << ' '; 

	system("pause");
	return 0;
}