#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Number
{
public:
    Number() { mysn = ++ initail_number; }
    Number (const Number &n) 
    { 
        mysn = ++ initail_number; 
        std::cout << "use copy constructor." << std::endl;
    }
    int mysn;
    static int initail_number;
};

int Number::initail_number = 0;

void f(const Number &s)
{
    cout << s.mysn << endl;
}


int main()
{
	Number a, b = a, c = b;

	cout << endl;
	f(a);
	f(b);
	f(c); 

	system("pause");
	return 0;
}