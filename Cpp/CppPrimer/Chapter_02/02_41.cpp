#include <iostream>
#include <string>

struct Sales_data
{
	std::string title;
	std::string author;
	float value = 0.0;
	float average = 0.0;
};

int main()
{
	Sales_data sd1, sd2;

	std::cin >> sd1.title >> sd1.author >> sd1.value;
	while (std::cin.get() != '\n');
	std::cin >> sd2.title >> sd2.author >> sd2.value;
	while (std::cin.get() != '\n');
	if (sd1.title == sd2.title && sd1.author == sd2.author)
	{
		sd1.average = sd2.average = (sd1.value + sd2.value) / 2;
		std::cout << "Title : " << sd1.title << "  Author : " << sd1.author
			<< "  Value : " << sd1.value << "  Average : " << sd1.average << std::endl;
	}
	else
	{
		std::cout << "Different" << std::endl;
	}

	system("pause");
	return 0;
}