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
    Screen myScreen(2, 2, 'c');
    char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
    pmf2 = &Screen::get;
    char c2 = (myScreen.*pmf2)(0, 0);
    cout << c2 << endl;

    using Get1 = char (Screen::*)() const;
    using Get2 = char (Screen::*)(Screen::pos, Screen::pos) const;
    Get1 get1 = &Screen::get;
    Get2 get2 = &Screen::get;
    cout << (myScreen.*get1)() << endl;
    cout << (myScreen.*get2)(0, 0) << endl;
    
    system("pause");
    return 0;
}