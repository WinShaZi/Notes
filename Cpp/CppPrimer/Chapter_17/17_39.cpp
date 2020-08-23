#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream iofile("data",fstream::ate|fstream::in|fstream::out);
	if (!iofile)
	{
		cerr << "Can't open file" << endl;
		exit(1);
	}
 
	auto end_mark = iofile.tellg();
	iofile.seekg(0, fstream::beg);
	size_t cnt = 0;
	string line;

	while (iofile && iofile.tellg() != end_mark && getline(iofile,line))
	{
		cnt += line.size() + 1;
		auto mark = iofile.tellg();
		iofile.seekp(0, fstream::end);
		iofile << cnt;
		if (mark != end_mark)
			iofile << " ";
		iofile.seekg(mark);
	}

	iofile.seekp(0, fstream::end);

	iofile << "\n";
	iofile.close();
 
	system("pause");
	return 0;
}