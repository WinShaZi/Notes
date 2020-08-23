
//1_9
//*******************************************************************************************

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int n = 50;
	int count = 0;

	while (n <= 100)
	{
		count += n;
		n++;
	}
	cout << count << endl;

	system("pause");
	return 0; 
 }

 //******************************************************************************************

 //2_41
 //******************************************************************************************

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

struct Sales_data
{
	string title;
	string author;
	float value = 0.0;
	float average = 0.0;
};

int main()
{
	Sales_data sd1, sd2;

	cin >> sd1.title >> sd1.author >> sd1.value;
	while (cin.get() != '\n');
	cin >> sd2.title >> sd2.author >> sd2.value;
	while (cin.get() != '\n');
	if (sd1.title == sd2.title && sd1.author == sd2.author)
	{
		sd1.average = sd2.average = (sd1.value + sd2.value) / 2;
		cout << "Title : " << sd1.title << "  Author : " << sd1.author
			<< "  Value : " << sd1.value << "  Average : " << sd1.average << endl;
	}
	else
	{
		cout << "Different" << endl;
	}

	system("pause");
	return 0;
}

 //******************************************************************************************