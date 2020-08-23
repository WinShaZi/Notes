//由于s是一个左值，经过包扩展std::forward<string>(s)， 
//将一个类型为string&的实参传递给string的构造函数（这里具体是string的拷贝构造函数）来构造一个新的元素