#include <iostream>

using namespace std;

int main()
{
    long long world, us;

    cout << "Enter the world's populaton : ";
    cin >> world;
    cout << "Enter the population of the US : ";
    cin >> us;
    cout << "The population of the US is " << double(us) / double(world) * 100;
    cout << "% of the world population."<< endl;

    system("pause");
    return 0;
}