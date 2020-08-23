#include <iostream>
#include <initializer_list>

using namespace std;

int sum(initializer_list<int> ili)
{
    int total = 0;

    for (auto &n : ili)
        total += n;

    return total;
}

int main()
{
    cout << sum({ 1, 2, 3, 4, 5 }) << endl;

    system("pause");
	return 0;
}