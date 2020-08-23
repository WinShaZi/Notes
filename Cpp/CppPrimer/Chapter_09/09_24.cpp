#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vs;

    cout << *vs.begin() << endl;
    cout << vs.front() << endl;
    cout << vs[0] << endl;
    cout << vs.at(0) << endl;

    system("pause");
    return 0;
}