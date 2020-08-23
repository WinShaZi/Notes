#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    { 
        cerr << "Not three paramaters" << endl;
        exit(1);
    }
    string st(argv[1]);

    st += argv[2];

    cout << st << endl;

    system("pause");
	return 0;
}