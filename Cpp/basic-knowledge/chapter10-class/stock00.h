#ifndef NEW_PROJECT_STOCK00_H
#define NEW_PROJECT_STOCK00_H
#include<string>

class Stock {
private:    //防止程序直接访问数据称为数据隐藏，类默认的访问控制权限就是private(类结构体的默认访问权限是public)
    std::string company; //公司名字
    long shares;         //公司持有的股票数量
    double share_val;    //每股的价格
    double total_val;    //股票的总价格
    void set_tot() {
        total_val = shares * share_val;
    }
public:    //将实现细节放在一起并将它们与抽线分开被称为封装
    void acquire(const std::string & co, long n,double pr);
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show();
};
#endif //NEW_PROJECT_STOCK00_H
