#include <iostream>
#include <string>

using namespace std;

class Screen
{
public:
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos wd, pos ht) : width(wd), height(ht), contents(ht*wd, ' ') {}
	Screen(pos wd, pos ht, char c) : width(wd), height(ht), contents(ht*wd, c) {}

	char get() const { return contents[cursor]; }
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &move(pos r, pos c);
	const Screen& display(ostream& os) const;
	Screen& display(ostream& os);
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	void do_display(ostream& os) const { os << contents; }
};


inline Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline Screen& Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
	pos row = r * width;
	contents[row + col] = ch;
	return *this;
}

Screen& Screen::display(ostream& os)
{
	do_display(os);
	return *this;
}

const Screen& Screen::display(ostream& os) const
{
	do_display(os);
	return *this;
}

int main()
{
	Screen myScreen(5, 5, 'x');

	myScreen.move(4, 0).set('#').display(cout);
	cout << endl;
	myScreen.display(cout);
	cout << endl;

	system("pause");
	return 0;
}