//不合法，因为编译器不知道应该先执行insert操作，还是执行*iter++操作
//或者执行完insert之后，应该先返回，还是对iter进行++操作