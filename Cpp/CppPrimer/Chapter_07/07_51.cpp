/*

例如这样的函数:

int getSize(const std::vector<int>&);
如果vector没有将其单参数构造函数定义为显式的。我们可以使用这样的函数:

getSize(34);
这是什么意思?很困惑。

但是std::字符串是不同的。通常，我们使用std::string替换const char *(C语言)。
所以当我们这样调用一个函数:

void setYourName(std::string);
setYourName("pezy");
这是很自然的

*/