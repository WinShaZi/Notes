#include <iostream>
#include <string>

using namespace std;

class Screen 
{
public:
    using pos = string::size_type;

    static const string Screen::*data() { return &Screen::contents; }
    static const pos Screen::*pcursor() { return &Screen::cursor; }
    Screen() = default;
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ }

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width+c]; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};

int main()
{
	const string Screen::*pdata = Screen::data();
    Screen myScreen(2, 2, 'c');
    auto s = myScreen.*pdata;
    cout << s << endl;

    const string::size_type Screen::*pcursor = Screen::pcursor();
    auto i = myScreen.*pcursor;
    cout << i << endl;

	system("pause");
	return 0;
}