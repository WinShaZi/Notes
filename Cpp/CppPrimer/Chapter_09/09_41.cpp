#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<char> vc = {'a', 'b', 'c', 'd', 'e'};
    string str(vc.begin(), vc.end());

    cout << str << endl;

	system("pause");
	return 0;
}