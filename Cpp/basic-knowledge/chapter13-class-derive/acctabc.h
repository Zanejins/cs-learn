//
// Created by zanejins on 2022/11/8.
//

#ifndef NEW_PROJECT_ACCTABC_H
#define NEW_PROJECT_ACCTABC_H
#include<iostream>
#include<string>

//Abstract Base Class
class AcctABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting {
        std::ios_base::fmtflags flags;
        std::streamsize pr;
    };
    const std::string &FullName() const {
        return fullName;
    }
    long AcctNum() const {
        return acctNum;
    }
    Formatting SetFormat() const;
    void Restore(Formatting & f) const;


public:
    AcctABC(const std::string & s= "NULLbody",long an = -1,double bal = 0.0);
    void Desposite(double amt);
    virtual void Withdraw(double amt) = 0; //pure virtual funciton
    double Balance() const {return balance;}
    virtual void ViewAcct() const = 0; //pure virtual function
    virtual ~AcctABC() { };
};


class Brass : public AcctABC {
public:
    Brass(const std::string &s ="Nullbody",long an=-1,double bal = 0.0) : AcctABC(s,an,bal) {
    }
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass() {

    }

};

// Brass Plus Account Class
class BrassPlus : public AcctABC {
private:
    double maxLoan;
    double rate;
    double owesBanks;

public:
    BrassPlus(const std::string &s = "Nullbody",long an=-1,double bal=0.0,double ml = 500,double r= 0.10);
    BrassPlus(const Brass & ba,double ml=500,double r=0.10);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) {maxLoan = m;}
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBanks = 0;}
};
#endif //NEW_PROJECT_ACCTABC_H
