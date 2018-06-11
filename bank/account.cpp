// account.cpp
// 2016/6/11
//

#include "account.h"
#include <iostream>
#include <cmath>
using namespace std;

double SavingsAccount::_total = 0;

SavingsAccount::SavingsAccount(const Date &date, 
		const string &id, double rate):
    _id(id), _balance(0), _rate(rate), 
    _lastDate(date), _accumulation(0)
{
    date.show();
    cout << "\t#" << id << " created" << endl;
}

void SavingsAccount::record(const Date &date, 
        double amount, const string &desc) 
{
    _accumulation = accumulate(date);
    _lastDate = date;
    amount = floor(amount * 100 + 0.5) / 100;
    _balance += amount;
    _total += amount;
    date.show();
    cout << "\t#" << _id << "\t" << amount << "\t" 
        << _balance << "\t" << desc << endl;
}

void SavingsAccount::error(const string &msg) const
{
    cout << "Error(#" << _id << "): " << msg << endl;
}

void SavingsAccount::deposit(const Date &date, 
        double amount, const string &desc)
{
    record(date, amount, desc);
}

void SavingsAccount::withdraw(const Date &date,
        double amount, const string &desc)
{
    if (amount > getBalance())
        error("not enough money");
    else
        record(date, -amount, desc);
}

void SavingsAccount::settle(const Date &date) 
{
    double interest = accumulate(date) * _rate
        / date.distance(Date(date.getYear()-1, 1, 1));
    if (interest != 0)
        record(date, interest, "interest");
    _accumulation = 0;
}

void SavingsAccount::show() const 
{
    cout << _id << "\tBalance: " << _balance;
}
