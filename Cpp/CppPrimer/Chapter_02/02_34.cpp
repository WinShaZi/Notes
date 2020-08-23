#include <iostream>
#include <iomanip>

int main()
{
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto &g = ci;

	std::cout << setiosflags(std::ios::right);
	std::cout << " a : " << std::setw(2) << a << "    b : " << std::setw(2) << b << std::endl;
	std::cout << " c : " << std::setw(2) << c << "   *d : " << std::setw(2) << *d << std::endl;
	std::cout << "*e : " << std::setw(2) << *e << "    g : " << std::setw(2) << g << std::endl;
	std::cout << std::endl;

	a = 42;
	b = 42;
	c = 42;
	*d = 42;
	e = &a;
	//g 是常量

	std::cout << " a : " << std::setw(2) << a << "    b : " << std::setw(2) << b << std::endl;
	std::cout << " c : " << std::setw(2) << c << "   *d : " << std::setw(2) << *d << std::endl;
	std::cout << "*e : " << std::setw(2) << *e << "    g : " << std::setw(2) << g << std::endl;
	std::cout << resetiosflags(std::ios::right);


	system("pause");
	return 0;
}