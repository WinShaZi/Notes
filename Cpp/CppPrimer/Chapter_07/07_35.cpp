/*

typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);              // double
    Type initVal();                 // double
private:
    int val;
};
Type Exercise::setVal(Type parm) {      // 返回的Type是string类型，形参类型是double类型
    val = parm + initVal;               // initVal调用的类中的
    return val;
}
// 会报错Type Exercise::setVal(Type parm)匹配不到类中的函数，因为返回值与类中不一致。改为：
// initVal函数只声明未定义，也会报错。
Exercise::Type Exercise::setVal(Type parm){}

*/