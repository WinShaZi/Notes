#include <iostream>

int main()
{
	int count_vowal = 0;
	int count_symbol = 0;
	int count_f = 0;
	char temp = '\0';
	const std::string st1 = "aoeiuv";
	const std::string st2 = " \n\r\t\v\f";
	char ch;

	while (std::cin.get(ch))
	{
		if (temp == 'f')
		{
			if (ch == 'f' || ch == 'l' || ch == 'i')
			{
				count_f++;
				temp = '\0';
			}
			else
				temp = '\0';
		}
		else
			temp = ch;

		if (st1.find(tolower(ch)) != std::string::npos)
			count_vowal++;
		else if (st2.find(ch) != std::string::npos)
			count_symbol++;
	}
	std::cout << "Vowal : " << count_vowal << std::endl;
	std::cout << "Tabulate : " << count_symbol << std::endl;
	std::cout << "ff, fl, fi : " << count_f << std::endl;

	system("pause");
	return 0;
}