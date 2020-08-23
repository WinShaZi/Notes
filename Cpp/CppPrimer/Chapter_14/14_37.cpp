#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Equal
{
private:
	int num;
public:
	Equal(int i) : num(i) { }
	bool operator()(int &i) const
	{
		return num == i;
	}
};

int main()
{
	vector<int> vi{ 0, 1, 2, 3, 4, 5 };

	replace_if(vi.begin(), vi.end(), Equal(3), 0);

	for (auto n : vi)
		cout << n << ' ';
	cout << endl;

	system("pause");
	return 0;
}