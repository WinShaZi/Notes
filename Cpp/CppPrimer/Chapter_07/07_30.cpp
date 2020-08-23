/*

优点：

1、使程序意图明确，更易读；

2、可以使形参名和要赋值的成员名相同。

如：std::string& setName(const string& name) { this->name = name; }

缺点：有些场景下比较多余

std::string const& getName() const { return this->name; }

*/