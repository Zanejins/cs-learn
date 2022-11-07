//
// Created by zanejins on 2022/11/7.
//

#ifndef NEW_PROJECT_BRASS_H
#define NEW_PROJECT_BRASS_H

#include<string>

//Brass class
class Brass {
private:
    std::string fullName;
    long acctNum;
    double balance;

public:
    Brass(const std::string & s = "Nullbody",long an = -1,double bal=0.0);
    void Deposit(double amt);
    //如果方法是通过引用或者指针而不是对象调用的
    //    1. 如果没有使用virtual关键字，程序将根据引用类型或者指针类型选择来选择方法
    //    2. 如果使用了virtual关键字，程序将根据引用或者指针指向的对象的类型来选择方法
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    //基类声明虚析构函数，这样做的目的是未来确保释放派生对象时，按照正确的顺序调用析构函数。
    virtual ~Brass();
};

//Brass Plus Account Class
class BrassPlus : public Brass{
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus(const std::string & s="Nullbody",long an = -1,double bal = 0.0,double ml=500,double r=0.11125);
    BrassPlus(const Brass & ba,double ml = 500,double r=0.11125);

    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) {maxLoan = m;}
    void ResetRate(double r) {rate = r;}
    void ResetRate() { owesBank = 0;}
};

#endif //NEW_PROJECT_BRASS_H
