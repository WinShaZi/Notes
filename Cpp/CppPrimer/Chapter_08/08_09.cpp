#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;


int main()
{
    stringstream ss;

    srand(unsigned(time(0)));

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (5 == j)
                ss << ' ';
            ss << char(rand() % 26 + 97);
        }
        ss << endl;
    }

    vector<string> vs;
    string st;

    while (getline(ss, st))
        vs.push_back(st);

    for (auto n : vs)
        cout << n << endl;

    system("pause");
    return 0;
}