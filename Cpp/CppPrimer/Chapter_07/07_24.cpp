/*

class Screen
{
public:
    using pos = string::size_type;

    Screen() = default;
    Screen(pos wd, pos ht) : width(wh), height(ht), contents(ht*wd, " ") {}
    Screen(pos wd, pos ht, char c) : width(wd), height(ht), contents(ht*wd, c) {}

    char getChar() const { return contents[cursor]; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};

*/