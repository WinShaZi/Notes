#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
 
int main()
{
	cout << unitbuf;
	cout << boolalpha << (5 < 4 ? true : false) << noboolalpha << endl;
	cout << showpos << showbase << hex << 1000 << " " << oct << 1000 
		<< " " << dec << 1000 << noshowbase << noshowpos << endl;
	cout << uppercase << 3.14159 << " " << hex << 1000 << dec 
		<< nouppercase << endl;
	cout << setfill('#') << setw(10) << internal << showpos << 1024 
		<< noshowpos << nounitbuf << ends << endl << flush;
	cout << setw(10) << left <<fixed<< 3.14 << " " << right 
		<<scientific<< 3.14 << endl;
	cout << hexfloat << 3.14159 << endl;
	cout << setprecision(3) << 3.14159 << endl;
	cout << setbase(8) << 1000 << endl;

	char ch;
	cin >> noskipws;
	while (cin >> ch && ch != 'q')
		cout << ch;
	cin >> skipws;
	cout << endl;
 
	cout << uppercase;
	cout << "default format: " << 100 * sqrt(2.0) << '\n'
		<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		<< "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		<< "hexidecimal: " << uppercase << hexfloat << 100 * sqrt(2.0) << '\n'
		<< "use defaults: " << defaultfloat << 100 * sqrt(2.0)
		<< endl;
 
	cout << setfill(' ');
	cout << left << setw(20) << "default format:" << setw(25) << right << 100 * sqrt(2.0) << '\n'
		<< left << setw(20) << "scientific:" << scientific << setw(25) << right << 100 * sqrt(2.0) << '\n'
		<< left << setw(20) << "fixed decimal:" << setw(25) << fixed << right << 100 * sqrt(2.0) << '\n'
		<< left << setw(20) << "hexidecimal:" << setw(25) << uppercase << hexfloat << right << 100 * sqrt(2.0) << '\n'
		<< left << setw(20) << "use defaults:" << setw(25) << defaultfloat << right << 100 * sqrt(2.0)
		<< endl;

	system("pause");
	return 0;
}