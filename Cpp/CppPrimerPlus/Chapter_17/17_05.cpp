#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

const string mat("mat.dat");
const string pat("pat.dat");
const string matnpat("matnpat.dat");

int main()
{
	ifstream fin_m(mat);
	ifstream fin_p(pat);
	ofstream fout(matnpat);
	if (!fin_m.is_open() || !fin_p.is_open() || !fout.is_open())
	{
		cerr << "Can't open file" << endl;
		exit(EXIT_FAILURE);
	}

	set<string> s_mat, s_pat, s_all;
	set<string>::iterator pd;
	string temp;

	while (getline(fin_m, temp))
		s_mat.insert(temp);
	while (getline(fin_p, temp))
		s_pat.insert(temp);

	cout << "Here is Mat's friends : " << endl;
	for (pd = s_mat.begin(); pd != s_mat.end(); pd++)
		cout << *pd << endl;
	cout << "\nHere is Pat's friends : " << endl;
	for (pd = s_pat.begin(); pd != s_pat.end(); pd++)
		cout << *pd << endl;
	fin_m.close();
	fin_p.close();

	set_union(s_mat.begin(), s_mat.end(), s_pat.begin(), s_pat.end(), inserter(s_all, s_all.begin()));
	for (pd = s_all.begin(); pd != s_all.end(); pd++)
		fout << *pd << endl;
	fout.close();

	ifstream fin(matnpat);
	if (!fin.is_open())
	{
		cerr << "Can't open \"" << matnpat << "\" file" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "\nHere is their friends : " << endl;
	while (!fin.eof() && getline(fin, temp))
		cout << temp << endl;
	fin.close();

	system("pause");
	return 0;
}