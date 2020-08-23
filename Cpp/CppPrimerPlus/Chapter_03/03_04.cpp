#include <iostream>

using namespace std;

const int DAY_SECOND = 86400;
const int HOUR_SECOND = 3600;
const int MINUTE_SECOND = 60;

int main()
{
    long _second;
    int day, hour, minute, second;

    cout << "Enter the number of seconds : ";
    cin >> _second;
    day = _second / DAY_SECOND;
    hour = (_second - day * DAY_SECOND) / HOUR_SECOND;
    minute = (_second - day * DAY_SECOND - hour * HOUR_SECOND) / MINUTE_SECOND;
    second = _second - day * DAY_SECOND - hour * HOUR_SECOND - minute * MINUTE_SECOND;
    cout << _second << " seconds = " << day << " days, " << hour << " hours, " << minute;
    cout << " minutes, " << second <<" seconds" << endl;

    system("pause");
    return 0;
}