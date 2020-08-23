#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>
#include <utility>
#include <sstream>

using namespace std;

template <typename T>
void debug_rep(const T &t)
{
	cout << "void debug_rep(const T &t)" << endl;
    cout << t << endl;
}
 
template <typename T>
void debug_rep(T *p)
{
	cout << "void debug_rep(T *p)" << endl;
    cout << *p << endl;
}

void debug_rep(char *p)
{
	cout << "void debug_rep(char *p)" << endl;
    debug_rep(p);
}
 
void debug_rep(const char *p)
{
	cout << "void debug_rep(const char *p)" << endl;
	debug_rep(string(p));
}

int main()
{
    int i = 1, *p = &i;
    const char *cp = "hello";

	debug_rep(i);
	cout << endl;
    debug_rep(p);
	cout << endl;
	debug_rep(*cp);
	cout << endl;
	debug_rep(cp);
	cout << endl;
	debug_rep("hello");

	system("pause");
    return 0;
}