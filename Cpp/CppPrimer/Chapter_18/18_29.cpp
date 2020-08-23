/*

构造顺序：Class、Base、D1、D2、MI、Class

析构顺序相反

1个Base部分，2个Class部分

(a)、错误，Class是Base的基类，而pb是Base类
(b)、正确，基类Class可以指向所有子类
(c)、错误、pb是Base类，MI是Base的子类
(d)、正确、D2是MI的基类

*/