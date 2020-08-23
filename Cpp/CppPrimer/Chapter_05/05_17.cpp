#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vi1(10, 100);
	vector<int> vi2(5, 100);

	auto pd = vi1.begin();

	for (auto n : vi2)
	{
		if (n != *pd)
		{
			cout << "false" << endl;
			
			system("pause");
			return 0;
		}
		pd++;
	}

	cout << "ture" << endl;

	system("pause");
	return 0;
}