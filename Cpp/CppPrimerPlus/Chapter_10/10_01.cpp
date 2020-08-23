
//bank.h
//*******************************************************************************************

#ifndef BANK_H_
#define BANK_H_

#include <string>

class BANK
{
private:
	std::string _name;
	long long _account;
	double _balance;
public:
	BANK(const std::string name, long long account, double blance);
	void show() const;
	void deposit(double money);
	void withdraw(double money);
};

#endif

//*******************************************************************************************

//bank.cpp
//*******************************************************************************************

#include <iostream>
#include <string>
#include "bank.h"

BANK::BANK(const std::string name, long long account, double balance)
{
	_name = name;
	_account = account;
	_balance = balance;
}

void BANK::deposit(double money)
{
	_balance += money;
}

void BANK::withdraw(double money)
{
	if (money > _balance)
	{
		std::cout << "Your balance is insufficient : " << std::endl;
		std::cout << "Input the amount : ";
		std::cin >> money;
	}
	_balance -= money;
}

void BANK::show() const
{
	std::cout << "Mr's " << _name << " : " << std::endl;
	std::cout << "Account : " << _account << std::endl;
	std::cout << "Balance : " << _balance << std::endl;
	std::cout << std::endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "bank.h"

inline void meau()
{
	using std::cout;
	using std::endl;

	cout << "Input 1 save money" << endl;
	cout << "Input 2 and get your money" << endl;
	cout << "Input : ";
}

int main()
{
	{
		using std::cout;
		using std::endl;
		using std::cin;

		int mode;
		long long ac;
		BANK bank = { "LIU",12345678,20000 };

		cout << "Input your account : ";
		while (cin >> ac)
		{
			if (ac != 12345678)
			{
				cout << "None!" << endl;
				cout << "Input your account : ";
				continue;
			}
			bank.show();
			meau();
			while (cin >> mode)
			{
				if (mode == 1)
				{
					double amount;

					cout << "Input the amount : ";
					if (!(cin >> amount))
						break;
					bank.deposit(amount);
				}
				else if (mode == 2)
				{
					double amount;

					cout << "Input the amount : ";
					if (!(cin >> amount))
						break;
					bank.withdraw(amount);
				}
				else
				{
					cout << "Input : ";
					continue;
				}
				bank.show();
				meau();
			}
			cout << "\nYour message : " << endl;
			bank.show();
			break;
		}
		cout << "Done!" << endl;
	}

	system("pause");
	return 0;
}

//*******************************************************************************************