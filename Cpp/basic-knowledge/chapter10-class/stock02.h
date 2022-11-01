//
// Created by zanejins on 2022/11/1.
//

#ifndef NEW_PROJECT_STOCK20_H
#define NEW_PROJECT_STOCK20_H
#include<iostream>
using namespace std;

class Stock {
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val;}

public:
    Stock();
    Stock(const std::string & co,long n=0,double pr = 0.0);
    ~Stock(); //do-nothing destructor
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show() const;
    const Stock & topval(const Stock & s) const;
};

#endif //NEW_PROJECT_STOCK20_H
