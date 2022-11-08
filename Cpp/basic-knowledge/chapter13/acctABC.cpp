#include<iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

//Abstract Base Class
AcctABC::AcctABC(const std::string &s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Desposite(double amt) {
    if(amt < 0)
        cout << "Negative deposit not allowed; deposit is cancelled.\n";
    else
        balance +=amt;
}

void AcctABC::Withdraw(double amt) {
    balance -=amt;
}

//protected methods for formatting
AcctABC::Formatting AcctABC::SetFormat() const {
    //set up ###.## format
    Formatting f;
    f.flags = cout.setf(ios_base::fixed,ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(AcctABC::Formatting &f) const {
    cout.setf(f.flags,ios_base::floatfield);
    cout.precision(f.pr);
}

//Brass methods
void Brass::Withdraw(double amt) {
    if(amt<0)
        cout<<"Withdrawal amount must be positive; Withdrawal canceled.\n";
    else if(amt<=Balance())
        AcctABC::Withdraw(amt);
    else
        cout<<"Withdrawal amount of $"<<amt<<" exceeds your balance.\n Withdrawal canceled"<<endl;
}

void Brass::ViewAcct() const {
    Formatting f= SetFormat();
    cout<<"Brass Client: "<<FullName()<<endl;
    cout<<"Account Number: "<<AcctNum()<<endl;
    cout<<"Balance: $"<<Balance()<<endl;
    Restore(f);
}

//BrassPlus Methods
BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double r) : AcctABC(s,an,bal){
    maxLoan = ml;
    owesBanks = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const {
    Formatting f= SetFormat();
    cout<<"BrassPlus Client: "<<FullName()<<endl;
    cout<<"Account Number: "<<AcctNum()<<endl;
    cout<<"Balance: $"<<Balance()<<endl;
    cout<<"Maximum loan: $"<<maxLoan<<endl;
    cout<<"Owed to bank: $"<<owesBanks<<endl;
    cout.precision(3);
    cout<<"Loan Rate: "<<100 * rate<<"%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt) {
    Formatting f= SetFormat();
    double bal = Balance();
    if(amt<=bal)
        AcctABC::Withdraw(amt);
    else if(amt<=bal+maxLoan-owesBanks) {
        double advance = amt -bal;
        owesBanks += advance * (1.0 + rate);
        cout<<"Bank advance: $"<<advance * rate<<endl;
        Desposite(advance); //继承类对象调用没有重载的父类函数
        AcctABC::Withdraw(amt); //继承类对象去调用重载的父类函数
    }
    else
        cout<<"Credit limit exceeded. Transaction cancelled.\n";
    Restore(f);
}