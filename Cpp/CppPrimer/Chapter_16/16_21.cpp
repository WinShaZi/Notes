#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Debugdelete
{
public:
	Debugdelete(ostream &s = cerr):os(s) { }
	template <typename T> void operator()(T *p) const
	{
		os<<"deleting..."<<endl;
		delete p;
	}
private:
	ostream &os;
};

int main()
{
	Debugdelete d;
	string *st = new string("string");
	
	cout << st->size() << endl;

	d(st);

	cout << st->size() << endl;

	system("pause");
	return 0;
}