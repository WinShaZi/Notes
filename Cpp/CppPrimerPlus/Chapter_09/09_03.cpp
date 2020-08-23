
#include<iostream>
#include<cstring>
#include<new>


using namespace std;

const int BUF = 512;
char buffer[BUF];

struct chaff
{
	char dross[20];
	int slag;
};

void get(chaff& str, char* ch);
void show(const chaff& str);

int main()
{
	chaff* p1 = new (buffer) chaff[2];

	for (int i = 0; i < 2; i++)
	{
		static int count = 0;
		cout << "#" << ++count << " : " << endl;
		cout << "Please enter the dross : ";
		char ch[20];
		cin.getline(ch, 20);
		get(p1[i], ch);
	}
	for (int i = 0; i < 2; i++)
		show(p1[i]);

    system("pause");
	return 0;
}

void get(chaff& str, char* ch)
{
	strcpy(str.dross, ch);
	cout << "Please enter the slag : ";
	cin >> str.slag;
	cin.get();
}

void show(const chaff& str)
{
	static int count = 0;
	cout << "#" << ++count << " : " << endl;
	cout << "dross of the chaff is : " << str.dross << endl;
	cout << "slag of the chaff is : " << str.slag << endl;
}