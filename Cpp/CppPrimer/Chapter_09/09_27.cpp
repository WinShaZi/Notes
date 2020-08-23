#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

int main()
{
	forward_list<int> fli{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto fli_prev = fli.before_begin();
	auto fli_curr = fli.begin();

	while (fli_curr != fli.end())
	{
		if (*fli_curr % 2)
			fli_curr = fli.erase_after(fli_prev);
		else
		{
			fli_prev = fli_curr;
			fli_curr++;
		}
	}

	for (auto n : fli)
		cout << n << ' ';

	system("pause");
	return 0;
}