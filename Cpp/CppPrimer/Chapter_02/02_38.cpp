//1：如果使用引用类型，auto会识别为其所指对象的类型，decltype则会识别为引用的类型。
//2：decltype(())双括号的差别

int i = 0, &r = i;
// same
auto a = i;
decltype(i) b = i;
// different
auto c = r;
decltype(r) d = i;