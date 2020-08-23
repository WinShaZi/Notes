/*

#include <iostream>
#icnlude <sstream>
#include <string>
#include <vector>
#include <fstream>

struct PersonInfo
{
    string name;
    vector<string> number;
    std::ostream& print (std::ostream& os);
};

std::ostream& PersonInfo::print (std::ostream& os)
{
    os << name << "\t";
    for (auto i : number) 
    {
        os << i << " ";
    }
    cout << endl;

    return os;
}

int main()
{
    string line, word;
    vector<PersonInfo> people;

    string fileName = "data";
    ifstream ifs(fileName);

    if (ifs) 
    {
        while (getline(ifs, line)) 
        {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
            while (record >> word) 
            {
                info.number.push_back(word);
            }
            people.push_back(info);
        }
    }
    else 
    {
        cout << "No data?" << endl;
    }
    for (auto i : people) 
    {
            i.print(cout);
    }
}

*/