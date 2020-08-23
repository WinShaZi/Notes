#include <iostream>
#include <string>
#include <stack>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	string str = "2+(1+3)";
	int result = 0;
	bool flag = false;
	stack<char> st;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			flag = true;
			continue;
		}
		else if (str[i] == ')')
		{
			flag = false;
		}

		if (true == flag)
		{
			st.push(str[i]);
		}
	}

	char ch;
	int a, b;
	string expression;

	while (!st.empty())
	{
		ch = st.top();
		st.pop();
		expression += ch;
	}

	a = stoi(expression.substr(0, 1));
	string symbol = expression.substr(1, 1);
	b = stoi(expression.substr(2, 1));

	if (symbol == "+")
	{
		result = a + b;
	}

	st.push(result);
	cout << result << endl;

	system("pause");
	return 0;
}