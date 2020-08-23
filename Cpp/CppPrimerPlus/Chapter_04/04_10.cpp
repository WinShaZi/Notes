#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<double, 3> ab;

    cout << "Input your three grade : ";
    cin >> ab[0] >> ab[1] >> ab[2];
    cout << "Your grades are : " << ab[0] << ' ' << ab[1] << ' ' << ab[2] << endl;
    cout << "Your average grade is : " << (ab[0] + ab[1] + ab[2]) / 3 << endl;

    system("pause");
    return 0;
}