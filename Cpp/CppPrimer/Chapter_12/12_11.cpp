//传给process的是由p.get()初始化的一个新的shared_ptr，与p指向同一块内存
//在process函数结束时，新的shared_ptr被释放，p就变成了一个空悬指针