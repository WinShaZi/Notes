#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <list>

using namespace std;

int main()
{
	srand(unsigned(time(0)));
    vector<int> vi0;

    for(int i = 0; i < 10000000; i++)
        vi0.push_back(rand() % 1000000);
        
    vector<int> vi(vi0);
    list<int> li(vi0.begin(), vi0.end());

    clock_t vi_start = clock();
    sort(vi.begin(),vi.end());
    clock_t vi_end = clock();
    double t_vi = double((vi_end - vi_start) / CLOCKS_PER_SEC);

    clock_t li_start = clock();
    li.sort();
    clock_t li_end = clock();
    double t_li = double((li_end - li_start) / CLOCKS_PER_SEC);

    cout << "Vector sort time : " << t_vi << " second" << endl;
    cout << "list sort time : " << t_li << " second" << endl;

    system("pause");
    return 0;
}