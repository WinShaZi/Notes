/*

a、可以见的：
Base1：ival、dval、cval、print
Base2：fval、print
Derived：sval、dval、print
MI：ival、dvec、print、foo
还有在foo里定义的ival


b、是：
dval：Base1::dval、Derived::dval、自己定义的int dval
ival ：MI::ival、Base1::ival
cval：Base1::cval、形参cval
print：Base1:print、Base2::print、Derived::print、MI::print


void foo(double cval)  
{  
    int dval;  
    dval = Base1::dval + Derived::dval;//c  
    Base2::fval = dvec.back();//d  
    Derived::sval[0] = Base1::cval;//e  
}

*/