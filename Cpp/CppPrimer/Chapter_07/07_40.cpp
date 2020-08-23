//class Date
{
 public:
    Date(int y, int m, int d) : year(y), month(m), day(d) { }
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    int getYear();
    int getMonth();
    int getDay();
 private:
    int year;
    int month;
    int day;
};