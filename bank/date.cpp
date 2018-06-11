// date.cpp
// 2018/6/11
//

#include "date.h"
#include <iostream>
#include <cstdlib>
using namespace std;

namespace {

const int DAYS_BEFORE_MONTH[] = {
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
};

}; //namespace

Date::Date(int year, int month, int day):
    _year(year), _month(month), _day(day)
{
    if (day <= 0 || day > getMaxDay()) {
        cout << "Invalid date: ";
        show();
        cout << endl;
        exit(1);
    }
    int years = year - 1;
    _totalDays = years*365 + years/4 - years/100 + years/400
            + DAYS_BEFORE_MONTH[_month-1] + _day;
    if (isLeapYear() && _month > 2) ++_totalDays;
}

int Date::getMaxDay() const 
{
    if (isLeapYear() && _month == 2)
        return 29;
    else
        return DAYS_BEFORE_MONTH[_month] 
                - DAYS_BEFORE_MONTH[_month-1];
}

void Date::show() const 
{
    cout << getYear() << "-" << getMonth() << "-" << getDay();
}

