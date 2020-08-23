#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;


int main()
{
    ofstream fout("data");

    srand(unsigned(time(0)));

    if (!fout.is_open())
    {
        cerr << "Open failure" << endl;
        exit(1);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            fout << char(rand() % 26 + 97);
        fout << endl;
    }
    fout.close();

    vector<string> vs;
    string st;
    ifstream fin("data");
    
    if (!fin.is_open())
    {
        cerr << "Open failure" << endl;
        exit(1);
    }

    while (fin >> st)
        vs.push_back(st);
    fin.close();

    for (auto n : vs)
    {
        istringstream ists(n);
        ists >> st;
        cout << st << endl;
    }

    system("pause");
    return 0;
}