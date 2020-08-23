#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	istream_iterator<int> in(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> vi;

	while (in != eof)
		vi.push_back(*in++);
	sort(vi.begin(), vi.end());
	unique_copy(vi.begin(), vi.end(), out);
	cout << endl;

	system("pause");
	return 0;
}