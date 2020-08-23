/*
auto newCallable = bind(callable, arg_list)；

其中，arg_list是一个用逗号分隔的参数列表，对应给callable的参数。当我们调用newCallable时，实际会调用callable。

arg_list中的参数可能会包含形如_n的名字，其中n是一个整数。

这些参数是“占位符”，表示newCallable的参数，它们占据了传递给newCallable的参数位置。

*/