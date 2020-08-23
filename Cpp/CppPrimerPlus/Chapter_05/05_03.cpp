#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<long long, 100> al;
    long long num, sum = 0ll;

    do
    {
        cin >> num;
        sum += num;
    } while (num != 0ll);

    cout << sum << endl;

    system("pause");
    return 0;
}