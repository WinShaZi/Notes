#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

using pos = string::size_type;
template <pos, pos> class Screen;

template <pos H, pos W> 
istream& operator>>(istream&, Screen<H, W>&);

template <pos H, pos W>
ostream& operator<<(ostream&, const Screen<H, W>&);

template <pos H, pos W> class Screen {
    friend istream& operator>><H, W>(istream&, Screen<H, W>&);
    friend ostream& operator<<<H, W>(ostream&, const Screen<H, W>&);

public:
    Screen() = default;
    Screen(char c) : contents(H * W, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * W + c]; }
    inline Screen& move(pos r, pos c);
    inline Screen& set(char ch);
    inline Screen& set(pos r, pos c, char ch);

private:
    pos cursor = 0;
    string contents;
};

template <pos H, pos W>
istream& operator>>(istream& is, Screen<H, W>& s)
{
    string input;
    is >> input;
    for (char ch : input) s.set(ch);
    return is;
}

template <pos H, pos W>
ostream& operator<<(ostream& os, const Screen<H, W>& s)
{
    for (pos r = 0; r != H; ++r) {
        for (pos c = 0; c != W; ++c) {
            os << s.get(r, c);
        }
        os << endl;
    }
    return os;
}

template <pos H, pos W> 
inline Screen<H, W>& Screen<H, W>::move(pos r, pos c)
{
    cursor = r * W + c;
    return *this;
}

template <pos H, pos W> 
inline Screen<H, W>& Screen<H, W>::set(char ch)
{
    contents[cursor++] = ch;
    cursor = min(cursor, H * W);
    return *this;
}

template <pos H, pos W>
inline Screen<H, W>& Screen<H, W>::set(pos r, pos c, char ch)
{
    contents[r * W + c] = ch;
    return *this;
}
int main()
{


	system("pause");
	return 0;
}