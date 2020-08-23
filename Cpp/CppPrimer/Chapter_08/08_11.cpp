/*

{
    string line, word;
    vector<PersonInfo> people;

    string fileName = "data";
    ifstream ifs(fileName);

    if (ifs) 
    {
        istringstream record;

        while (getline(ifs, line)) 
        {
            PersonInfo info;
            record.clear();
            record.str(line);
            record >> info.name;

            while (record >> word) {
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

    system("pause");
    return 0;
}

*/