#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<long double, 200> alb;
    
    alb[0] = 1;
    for (int i = 1; i <= 100; i++)
        alb[i]= alb[i - 1] * i;
    for (int i = 0; i <= 100;i++)
        cout << i << "! = " << alb[i] << endl;

    system("pause");
    return 0;
}