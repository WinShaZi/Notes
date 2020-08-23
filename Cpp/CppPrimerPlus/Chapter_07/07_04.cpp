#include <iostream>

using namespace std;

long double probability(unsigned numbers, unsigned picks);

int main()
{
    double total_1, choices_1, total_2, choices_2;

    cout << "Input the first game rule : ";
    while ((cin >> total_1 >> choices_1) && choices_1 <= total_1)
    {
		cout << "Input the second game rule : ";
		if (cin >> total_2 >> choices_2 && choices_2 <= total_2)
		{
        	cout << "You have one chance in ";
       		cout << probability(total_1, choices_1) * probability(total_2, choices_2);
        	cout << " of winning." << endl;
			cout << "Input the first game rule : ";
		}
	}
    cout << "bye" << endl;

	system("pause");
    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0; 
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p ;

    return result;
}