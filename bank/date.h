// date.h
// 2018/6/11
// 

#ifndef __DATE_H__
#define __DATE_H__

class Date {
public:
    Date(int year, int month, int day);
    int getYear() const { return _year; }
    int getMonth() const { return _month; }
    int getDay() const { return _day; }
    int getMaxDay() const;
    bool isLeapYear() const 
    {
        return (_year % 4 == 0 && _year % 100 != 0)
             || _year % 400 == 0;
    }
    void show() const;
    int distance(const Date &date) const
    {
        return _totalDays - date._totalDays;
    }

private:
    int _year;
    int _month;
    int _day;
    int _totalDays;
};

#endif //   __DATE_H__
