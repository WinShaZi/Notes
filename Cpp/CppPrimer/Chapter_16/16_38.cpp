//make_shared模板的使用需要以“显示模板实参”的方式使用，如上题所示make_shared<string>(10, 9),如果不传递显示 
//模板实参string类型,make_shared无法从(10, '9')两个模板参数中推断出其创建对象类型