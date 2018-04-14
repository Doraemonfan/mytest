#include <iostream>
using namespace std;


class Date {

          friend ostream& operator<<(ostream &out, const Date &d);
private:
          int MONTH[13] = {
                    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
          };
          int _year;
          int _month;
          int _day;

          bool isLeap();
          int sumDays();
          Date todate(int days);

public:
          Date(int y, int m, int d):
                    _year(y), _month(m), _day(d)
          {
                    if (isLeap()) MONTH[2] = 29;
                    else MONTH[2] = 28;
          }

          Date tomorrow();
          Date yesterday();
};

bool Date::isLeap()
{
          if (_year % 4 == 0 &&
                    (_year % 400 == 0 || _year % 100 != 0))
                    return true;
          else return false;
}

int Date::sumDays()
{
          int sumdays = 0;
          for (int i = 1; i < _month; ++i)
                    sumdays += MONTH[i];
          return sumdays += _day;
}

Date Date::todate(int days)
{
          int year = _year;
          int month = 1;
          for (int i = 1; i <= 12 && days > MONTH[i]; ++i)
          {
                    days -= MONTH[i];
                    ++month;
          }
          int day = days;
          return Date(year, month, day);
}

Date Date::tomorrow()
{
          int tordays = sumDays() + 1;
          if (tordays == 366 && !isLeap() || tordays == 367)
                    return Date(_year + 1, 1, 1);
          return todate(tordays);
}

Date Date::yesterday()
{
          int yesdays = sumDays() - 1;
          if (yesdays == 0) return Date(_year - 1, 12, 31);
          return todate(yesdays);
}

ostream& operator<<(ostream &out, const Date &d)
{
           out << d._year << "/" << d._month << "/" << d._day;
}

int main()
{
          int year;
          int month;
          int day;
          while (1) {
                    cout << "Please input your date: ";
                    cin >> year >> month >> day;
                    Date d(year, month, day);
                    cout << "today: " <<  d << endl;
                    cout << "yesterday: " << d.yesterday() << endl;
                    cout << "tomorrow: " <<  d.tomorrow() << endl;
          }
          return 0;
}
