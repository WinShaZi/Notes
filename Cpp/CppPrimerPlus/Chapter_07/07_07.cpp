#include <iostream>

using namespace std;

const int MAX = 5;

double* fill_array(double ar[], int limit);
void show_array(const double ar[], double* pe);
void revalue(double r, double ar[], double* pe);

int main()
{
    double properties[MAX];
    double* pe = fill_array(properties, MAX);

    show_array(properties, pe);
    if (pe != NULL)
    {
        cout << "Enter revaluation factor : ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; Please enter a number : ";
        }
        revalue(factor, properties, pe);
        show_array(properties, pe);
    }
    cout << "Done." << endl;

	system("pause");
    return 0;
}

double* fill_array(double ar[], int limit)
{
    double temp;
    int i;
	double* pe = NULL;

    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << " : ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; input process terminated." << endl;
           break;
        }
        else if (temp < 0)
            break;
        ar[i] = temp;
    }

    return pe = &ar[i];
}

void show_array(const double ar[], double* pe)
{
	for(int i = 0; ar[i] != *pe; i++)
	{
		cout << "Property #" << i + 1 << " : $";
		cout << ar[i] << endl;  
	}
}

void revalue(double r, double ar[], double* pe)
{ 
	for(int i = 0; ar[i] != *pe; i++)
		ar[i] *= r;
}
