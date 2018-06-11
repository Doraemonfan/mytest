// account.h
// 2018/6/11
//

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "date.h"
#include <string>

class SavingsAccount {
public:
    SavingsAccount(const Date &date,
            const std::string &id, double rate);
    void deposit(const Date &date, double amount,
            const std::string &desc);
    void withdraw(const Date &date, double amount,
            const std::string &desc);
    void settle(const Date &date);
    void show() const;

    const std::string& getid() const { return _id; }
    double getBalance() const { return _balance; }
    double getRate() const { return _rate; }
    static double getTotal() { return _total; }
private:
    std::string _id;
    double _balance;
    double _rate;
    Date _lastDate;
    double _accumulation;
    static double _total;

    void record(const Date &date, double amount, 
            const std::string &desc);
    void error(const std::string &msg) const;
    double accumulate(const Date &date) const
    {
        return _accumulation + 
			_balance * date.distance(_lastDate);
    }
};

#endif // __ACCOUNT_H__
