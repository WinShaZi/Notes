//不能拷贝unique_ptr的规则有一个例外：我们可以拷贝或赋值一个将要被销毁的unique_ptr，
//编译器知道要返回的对象将要被销毁，因此会执行一种特殊的"拷贝" -- 移动。最常见的就是从函数返回unique_ptr