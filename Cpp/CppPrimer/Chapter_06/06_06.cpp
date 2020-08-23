#include <iostream>

using namespace std;

int fact()
{
	static int count = 0;

	count++;

	return count;
}

int main()
{
	int i = 100;

	for (int i = 0; i < 10; i++)
		cout << i << ' ' << fact() << ' ';
	cout << endl << i << endl;


	system("pause");
	return 0;
}

//局部变量：形参和函数体内部定义的变量统称为局部变量（注意其作用域）

//局部静态对象：知道程序的结束才被销毁的对象，不受块的约束